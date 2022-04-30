#ifndef MATRIXBUTTONS_H
#define MATRIXBUTTONS_H

#include "matrix.h"

#include <QWidget>

namespace Ui {
class MatrixButtons;
}

class MatrixButtons : public QWidget
{
    Q_OBJECT

public:
    explicit MatrixButtons(Matrix &matrix, Matrix &lastMatrix, QWidget *parent = nullptr);
    ~MatrixButtons();

private slots:
    void on_calcDetBtn_clicked();

    void on_calcAlgAddBtn_clicked();

private:
    Ui::MatrixButtons *ui;
    Matrix *matrix;
    Matrix *lastMatrix;
};

#endif // MATRIXBUTTONS_H
