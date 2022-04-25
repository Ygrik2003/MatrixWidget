#include "matrix.h"

Matrix::Matrix()
{

}

Matrix::Matrix(int w, int h)
{
    this->setSize(w, h);
}

Matrix::Matrix(QSize size)
{
    this->setSize(size);
}

void Matrix::setSize(int w, int h)
{

    matrix.resize(h);
    for (int i = 0; i < h; i++)
        matrix.resize(w);
}

void Matrix::setSize(QSize size)
{
    this->setSize(size.width(), size.height());
}

QVector<float> &Matrix::operator[](const int index)
{
    return matrix[index];
}

Matrix &Matrix::operator+(Matrix matrix)
{
    if (this->matrix.size() != matrix.matrix.size())
        throw MatrixException("MatrixMathError", "You cannot summary matrix different size");

    Matrix temp;
    for (int i = 0; i < this->matrix.size(); i++)
        for (int j = 0; j < this->matrix[i].size(); j++)
            //temp = this->matrix[i][j] + matrix[i][j];
    return temp;
}

MatrixException::MatrixException(QString err, QString info)
{
    this->err = err;
    this->info = info;
}

void MatrixException::printError()
{
    qDebug() << QString("[%1] : %2").arg(err, info);
}
