#ifndef MATRIXBUTTONS_H
#define MATRIXBUTTONS_H

#include "matrix.h"
#include "matrixwidget.h"

#include <QWidget>

namespace Ui {
class MatrixButtons;
}

class MatrixButtons : public QWidget
{
    Q_OBJECT

public:
    explicit MatrixButtons(MatrixWidget &matrix, Matrix &lastMatrix, QWidget *parent = nullptr);
    ~MatrixButtons();

private slots:
    void on_calcDetBtn_clicked();

    void on_calcAlgAddBtn_clicked();

    void on_transposeBtn_clicked();

    void on_reverseBtn_clicked();

    void on_delRowBtn_clicked();

    void on_delColBtn_clicked();

    void on_backBtn_clicked();

    void on_swapColsBtn_clicked();

    void on_swapRowsBtn_clicked();

    void on_addRowBtn_clicked();

    void on_addColBtn_clicked();

private:
    Ui::MatrixButtons *ui;
    MatrixWidget *matrix;
    Matrix *lastMatrix;
};

#endif // MATRIXBUTTONS_H
