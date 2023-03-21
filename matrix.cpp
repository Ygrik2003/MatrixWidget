#include "matrix.h"

Matrix::Matrix()
{
    this->setSize(1, 1);
}

Matrix::Matrix(int height, int width)
{
    this->setSize(height, width);
}

Matrix::Matrix(msize size)
{
    this->setSize(size);
}

Matrix::Matrix(const Matrix &a)
{
    matrix = a.matrix;
}

void Matrix::setSize(int height, int width)
{
    if (height <= 0 || width <= 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(height, width));

    matrix.resize(height);
    for (int i = 0; i < height; i++)
        matrix[i].resize(width);
}

void Matrix::setSize(msize size)
{
    if (size.height <= 0 || size.width <= 0)
        throw MatrixException(MatrixException::errors::IndexError, size);

    this->setSize(size.height, size.width);
}

msize Matrix::getSize() const
{
    return msize(matrix.size(), matrix[0].size());
}

Matrix Matrix::operator+(Matrix matrix)
{
    if (this->getSize() != matrix.getSize())
        throw MatrixException(MatrixException::errors::SumError, this->getSize(), matrix.getSize());

    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp.matrix[i][j] = this->matrix[i][j] + matrix.matrix[i][j];
    return temp;
}

Matrix Matrix::operator-(Matrix matrix)
{
    if (this->getSize() != matrix.getSize())
        throw MatrixException(MatrixException::errors::SubError, this->getSize(), matrix.getSize());

    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp.matrix[i][j] = this->matrix[i][j] - matrix.matrix[i][j];
    return temp;
}

Matrix Matrix::operator*(const double number)
{
    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp.matrix[i][j] = this->matrix[i][j] * number;
    return temp;
}

Matrix operator*(const double number, Matrix matrix)
{
    Matrix temp(matrix.getSize());
    for (int i = 0; i < matrix.getSize().height; i++)
        for (int j = 0; j < matrix.matrix[i].size(); j++)
            temp.matrix[i][j] = matrix.matrix[i][j] * number;
    return temp;
}

Matrix Matrix::operator*(Matrix matrix)
{
    if (this->matrix[0].size() != matrix.matrix.size())
        throw MatrixException(MatrixException::errors::MulError, this->getSize(), matrix.getSize());

    Matrix temp(this->matrix.size(), matrix.matrix[0].size());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            for (int k = 0; k < matrix.matrix.size(); k++)
                temp.matrix[i][j] += this->matrix[i][k] * matrix.matrix[k][j];
    return temp;

}

Matrix Matrix::operator/(const double number)
{
    if (number == 0)
        throw MatrixException(MatrixException::errors::ZeroDivisionError);

    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp.matrix[i][j] = this->matrix[i][j] / number;
    return temp;

}

Matrix &Matrix::operator=(const Matrix matrix)
{
    this->matrix = matrix.matrix;
    return *this;
}

double Matrix::determinant()
{
    if (this->matrix[0].size() != matrix.size())
        throw MatrixException(MatrixException::errors::DeterminantError, getSize());

    return det(matrix);
}

double Matrix::algAddition(int i, int j)
{
    Matrix temp;
    double a = matrix[i][j];
    temp.matrix = matrix;
    temp.delRow(i);
    temp.delColumn(j);
    return a * pow(-1, i + j) * temp.determinant();
}

void Matrix::transpose()
{
    Matrix temp(matrix[0].size(), matrix.size());
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            temp.matrix[j][i] = matrix[i][j];
    matrix = temp.matrix;
}

void Matrix::reverse()
{
    double d = determinant();
    if (d == 0)
        throw MatrixException(MatrixException::errors::ReverseMatrixError);


    Matrix tmp(matrix.size(), matrix.size());
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix.size(); j++)
            tmp.matrix[i][j] = (1 / d) * algAddition(i, j);
    matrix = tmp.matrix;
}

QVector<double> Matrix::getRow(int i)
{
    if (i >= matrix.size() || i < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(i, 0));
    return matrix[i];
}

QVector<double> Matrix::getColumn(int j)
{
    if (j >= matrix[0].size() || j < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(0, j));
    QVector<double> tmp;
    for (int i = 0; i < this->getSize().height; i++)
        tmp.append(matrix[i][j]);
    return tmp;
}

double Matrix::getElement(int i, int j)
{
    if ((i >= matrix.size() || i < 0) || (j >= matrix[0].size() || j < 0))
        throw MatrixException(MatrixException::errors::IndexError, msize(i, j));
    return matrix[i][j];
}

void Matrix::setElement(int i, int j, double value)
{
    if ((i >= matrix.size() || i < 0) || (j >= matrix[0].size() || j < 0))
        throw MatrixException(MatrixException::errors::IndexError, msize(i, j));
    matrix[i][j] = value;
}

void Matrix::delRow(int i)
{
    if (i >= matrix.size() || i < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(i, 0));
    matrix.remove(i);
}

void Matrix::delColumn(int j)
{
    if (j >= matrix[0].size() || j < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(0, j));
    for (int i = 0; i < matrix.size(); i++)
        matrix[i].remove(j);
}

void Matrix::addRow(int i, QVector<double> a)
{
    if (i >= matrix.size() || i < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(i, 0));
    if (matrix[0].size() != a.size())
        throw MatrixException(MatrixException::errors::SizeError, getSize(), msize(1, a.size()));
    matrix.insert(i, a);
}

void Matrix::addRow()
{
    QVector<double> tmp;
    tmp.resize(matrix[0].size());
    matrix.append(tmp);
}

void Matrix::addColumn(int j, QVector<double> a)
{
    if (j >= matrix[0].size() || j < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(0, j));
    if (matrix.size() != a.size())
        throw MatrixException(MatrixException::errors::SizeError, getSize(), msize(a.size(), 1));
    for (int i = 0; i < a.size(); i++)
        matrix[i].insert(j, a[i]);
}

void Matrix::addColumn()
{
    for (int i = 0; i < matrix.size(); i++)
        matrix[i].append(0);
}

void Matrix::swapRows(int i1, int i2)
{
    if (i1 >= matrix.size() || i1 < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(i1, 0));
    if (i2 >= matrix.size() || i2 < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(i2, 0));
    std::swap(matrix[i1], matrix[i2]);
}

void Matrix::swapColumns(int j1, int j2)
{
    if (j1 >= matrix[0].size() || j1 < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(0, j1));
    if (j2 >= matrix[0].size() || j2 < 0)
        throw MatrixException(MatrixException::errors::IndexError, msize(0, j2));

    for (int i = 0; i < matrix[0].size(); i++)
        std::swap(matrix[i][j1], matrix[i][j2]);
}


double Matrix::det(QVector<QVector<double>> a)
{
    if (a.size() == 1)
        return a[0][0];
    double d = 0;
    QVector<QVector<double>> tmp;
    for (int j = 0; j < a.size(); j++) { // Разложение по первой строке (i = 0)
        tmp = a;
        tmp.remove(0);
        for (int i = 0; i < tmp.size(); i++)
            tmp[i].remove(j);
        d += a[0][j] * pow(-1, j) * det(tmp);
    }
    return d;
}

MatrixException::MatrixException(errors type, msize a, msize b)
{
    switch (type){
    case MatrixException::SumError:
        err = "SumError";
        info = QString("Can't summary matrix's sizes of (%1, %2) and (%3, %4)").arg(a.height).arg(a.width).arg(b.height).arg(b.width);
        break;
    case MatrixException::SubError:
        err = "SubError";
        info = QString("Can't subtraction matrix's sizes of (%1, %2) and (%3, %4)").arg(a.height).arg(a.width).arg(b.height).arg(b.width);
        break;
    case MatrixException::MulError:
        err = "MulError";
        info = QString("Can't multiplied matrix's sizes of (%1, %2) and (%3, %4)").arg(a.height).arg(a.width).arg(b.height).arg(b.width);
        break;
    case MatrixException::ZeroDivisionError:
        err = "ZeroDivisionError";
        info = "Can't division by zero";
        break;
    case MatrixException::ReverseMatrixError:
        err = "ReverseMatrixError";
        info = "Can't calculate reverse matrix with det() = 0";
        break;
    case MatrixException::IndexError:
        err = "IndexError";
        info = QString("Can't treat to element (%1, %2)").arg(a.height).arg(a.width);
        break;
    case MatrixException::DeterminantError:
        err = "DeterminateError";
        info = QString("Can't calculate determinate of matrix with size (%1, %2)").arg(a.height).arg(a.width);
        break;
    case MatrixException::errors::SizeError:
        err = "SizeError";
        info = QString("Can't do this operation with matrix sizes of (%1, %2) and (%3, %4)").arg(a.height).arg(a.width).arg(b.height).arg(b.width);
        break;
    }
    qDebug() << QString("[%1]: %2").arg(err, info);
}

void MatrixException::printError()
{
    qDebug() << QString("[%1]: %2").arg(err, info);
}
