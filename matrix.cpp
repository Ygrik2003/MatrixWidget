#include "matrix.h"

Matrix::Matrix()
{
    this->setSize(1, 1);
}

Matrix::Matrix(int w, int h)
{
    this->setSize(w, h);
}

Matrix::Matrix(QSize size)
{
    this->setSize(size);
}

Matrix::Matrix(const Matrix &a)
{
    matrix = a.matrix;
}

void Matrix::setSize(int w, int h)
{

    matrix.resize(h);
    for (int i = 0; i < h; i++)
        matrix[i].resize(w);
}

void Matrix::setSize(QSize size)
{
    this->setSize(size.width(), size.height());
}

int Matrix::size()
{
    return this->matrix.size();
}

QSize Matrix::getSize() const
{
    if (matrix.size() == 0)
        return QSize(0, 0);
    return QSize(matrix.size(), matrix[0].size());
}

QVector<double> &Matrix::operator[](const int index)
{
    return matrix[index];
}

Matrix Matrix::operator+(Matrix matrix)
{
    if (this->getSize() != matrix.getSize())
        throw MatrixException(MatrixException::errors::SizeError, this->getSize(), matrix.getSize());

    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp[i][j] = this->matrix[i][j] + matrix[i][j];
    return temp;
}

Matrix Matrix::operator-(Matrix matrix)
{
    if (this->getSize() != matrix.getSize())
        throw MatrixException(MatrixException::errors::SizeError, this->getSize(), matrix.getSize());

    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp[i][j] = this->matrix[i][j] - matrix[i][j];
    return temp;
}

Matrix Matrix::operator*(const double number)
{
    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp[i][j] = this->matrix[i][j] * number;
    return temp;
}

Matrix operator*(const double number, Matrix matrix)
{
    Matrix temp(matrix.getSize());
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            temp[i][j] = matrix[i][j] * number;
    return temp;
}

Matrix Matrix::operator*(Matrix matrix)
{
    if (this->matrix[0].size() != matrix.matrix.size())
        throw MatrixException(MatrixException::errors::SizeError, this->getSize(), matrix.getSize());

    Matrix temp(this->matrix.size(), matrix.matrix[0].size());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            for (int k = 0; k < matrix.matrix.size(); k++)
                temp[i][j] += this->matrix[k][j] * matrix[i][k];
    return temp;

}

Matrix Matrix::operator/(const double number)
{
    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp[i][j] = this->matrix[i][j] / number;
    return temp;

}

Matrix &Matrix::operator=(const Matrix matrix)
{
    this->matrix = matrix.matrix;
    return *this;
}

double Matrix::determinant()
{
    if (!matrix.size())
        throw MatrixException(MatrixException::errors::IndexError, getSize());
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
    if (!matrix.size())
        throw MatrixException(MatrixException::errors::IndexError, getSize());

    Matrix temp(matrix[0].size(), matrix.size());
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            temp[j][i] = matrix[i][j];
}

void Matrix::reverse()
{
    double d = determinant();
    if (d == 0)
        throw MatrixException(MatrixException::errors::ReverseMatrixError);


    Matrix tmp(matrix.size(), matrix.size());
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix.size(); j++)
            tmp[i][j] = d * algAddition(i, j);
    matrix = tmp.matrix;
}

void Matrix::delRow(int i)
{
    matrix.remove(i);
}

void Matrix::delColumn(int j)
{
    for (int i = 0; i < matrix[0].size(); i++)
        matrix[i].remove(j);
}

void Matrix::swapRows(int i1, int i2)
{
    std::swap(matrix[i1], matrix[i2]);
}

void Matrix::swapColumns(int j1, int j2)
{
    for (int i = 0; i < matrix[0].size(); i++)
        std::swap(matrix[i][j1], matrix[i][j2]);
}

double Matrix::det(QVector<QVector<double>> a)
{
    if (a.size() == 1)
        return a[0][0];
    double d = 0;
    QVector<QVector<double>> tmp = a;
    for (int j = 0; j < a.size(); j++) { // i = 0
        tmp.remove(0);
        for (int i = 0; tmp.size(); i++)
            tmp[i].remove(j);
        d += pow(-1, j) * det(tmp);
    }
    return d;
}

MatrixException::MatrixException(errors type, QSize a, QSize b)
{
    switch (type){
    case MatrixException::ReverseMatrixError:
        err = "ReverseMatrixError";
        info = "Can't calculate reverse matrix";
        break;
    case MatrixException::IndexError:
        err = "IndexError";
        info = QString("Can't treat to element (%1, %2)").arg(a.height()).arg(a.width());
        break;
    case MatrixException::MathError:
        err = "MathError";
        info = "Can't division by 0";
        break;
    case MatrixException::DeterminantError:
        err = "DeterminateError";
        info = QString("Can't calculate determinate of matrix with size (%1, %2)").arg(a.height()).arg(a.width());
        break;
    case MatrixException::TypeError:
        err = "TypeError";
        info = "";
        break;
    case MatrixException::errors::SizeError:
        err = "SizeError";
        info = QString("Can't do this operation with matrixs sizes of (%1, %2) and (%3, %4)").arg(a.height()).arg(a.width()).arg(b.height()).arg(b.width());
        break;
    }
}

void MatrixException::printError()
{
    qDebug() << QString("[%1]: %2").arg(err, info);
}
