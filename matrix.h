#ifndef MATRIX_H
#define MATRIX_H

#include <QSize>
#include <QVector>
#include <QDebug>

class MatrixException
{
public:
    enum errors
    {
        SizeError,
        IndexError,
        MathError,
        DeterminantError,
        TypeError
    };

    MatrixException(errors type);
    void printError();


private:
    QString err, info;
};

class Matrix
{
public:
    Matrix();
    Matrix(int, int);
    Matrix(QSize);
    Matrix(const Matrix &);

    void setSize(int, int);
    void setSize(QSize);
    int size();
    QSize getSize() const;

    QVector<double> &operator[](const int index);
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    Matrix operator*(const double);
    friend Matrix operator*(const double, Matrix);
    Matrix operator/(const double);
    Matrix &operator=(const Matrix);

    double determinant();

private:
    double det(QVector<QVector<double>>);
    QVector<QVector<double>> matrix;
};

#endif // MATRIX_H
