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
        throw MatrixException(MatrixException::errors::SizeError);

    Matrix temp(this->getSize());
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            temp[i][j] = this->matrix[i][j] + matrix[i][j];
    return temp;
}

Matrix Matrix::operator-(Matrix matrix)
{
    if (this->getSize() != matrix.getSize())
        throw MatrixException(MatrixException::errors::SizeError);

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
        throw MatrixException(MatrixException::errors::SizeError);

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
        throw MatrixException(MatrixException::errors::IndexError);
    if (this->matrix[0].size() != matrix.size())
        throw MatrixException(MatrixException::errors::DeterminantError);

    return det(matrix);
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

MatrixException::MatrixException(errors type)
{
    switch (type){
    case MatrixException::IndexError:
        err = "IndexError";
        info = "";
        break;
    case MatrixException::MathError:
        err = "MathError";
        info = "";
        break;
    case MatrixException::DeterminantError:
        err = "DeterminateError";
        info = "Can't calculate determinate of matrix";
        break;
    case MatrixException::TypeError:
        err = "TypeError";
        info = "";
        break;
    case MatrixException::errors::SizeError:
        err = "SizeError";
        info = "";
        break;
    }
}

void MatrixException::printError()
{
    qDebug() << QString("[%1]: %2").arg(err, info);
}
