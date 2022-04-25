#ifndef MATRIX_H
#define MATRIX_H

#include <QSize>
#include <QVector>
#include <QDebug>

class MatrixException
{
public:
    MatrixException(QString err, QString info);
    void printError();

private:
    QString err, info;
};

class Matrix
{
public:
    Matrix(int, int);
    Matrix(QSize);

    void setSize(int, int);
    void setSize(QSize);

    QVector<float> &operator[](const int index);
    Matrix &operator+(Matrix);
    Matrix &operator-(Matrix);
    Matrix &operator*(Matrix);
    Matrix &operator*(const float);
    friend Matrix &operator*(float, Matrix);
    Matrix &operator/(const float);
    Matrix &operator=(const Matrix);

private:
    Matrix();

    QVector<QVector<float>> matrix;
};

#endif // MATRIX_H
