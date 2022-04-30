#include "matrixbuttons.h"
#include "ui_matrixbuttons.h"

MatrixButtons::MatrixButtons(MatrixWidget &matrix, Matrix &lastMatrix, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatrixButtons)
{
    ui->setupUi(this);
    this->matrix = &matrix;
    this->lastMatrix = &lastMatrix;
}

MatrixButtons::~MatrixButtons()
{
    delete ui;
}

void MatrixButtons::on_calcDetBtn_clicked()
{
    ui->detLbl->setText("Determinant = " + QString::number(matrix->matrix.determinant()));
}


void MatrixButtons::on_calcAlgAddBtn_clicked()
{
    int i = ui->iEdit->text().toInt();
    int j = ui->jEdit->text().toInt();
    ui->algAddLbl->setText("AlgAdd = " + QString::number(matrix->matrix.algAddition(i, j)));
}


void MatrixButtons::on_transposeBtn_clicked()
{
    *lastMatrix = matrix->matrix;
    matrix->matrix.transpose();
    matrix->update();
}


void MatrixButtons::on_reverseBtn_clicked()
{
    *lastMatrix = matrix->matrix;
    matrix->matrix.reverse();
    matrix->update();
}


void MatrixButtons::on_delRowBtn_clicked()
{
    *lastMatrix = matrix->matrix;
    matrix->matrix.delRow(ui->iDelEdit->text().toInt());//DADA TODO
    matrix->update();
}


void MatrixButtons::on_delColBtn_clicked()
{
    *lastMatrix = matrix->matrix;
    matrix->matrix.delColumn(ui->jDelEdit->text().toInt());//DADA TODO
    matrix->update();
}


void MatrixButtons::on_backBtn_clicked()
{
    std::swap(matrix->matrix, *lastMatrix);
    matrix->update();
}


void MatrixButtons::on_swapColsBtn_clicked()
{
    int j1 = ui->j1Edit->text().toInt();
    int j2 = ui->j2Edit->text().toInt();
    *lastMatrix = matrix->matrix;
    matrix->matrix.swapColumns(j1, j2);
    matrix->update();
}


void MatrixButtons::on_swapRowsBtn_clicked()
{
    int i1 = ui->i1Edit->text().toInt();
    int i2 = ui->i2Edit->text().toInt();
    *lastMatrix = matrix->matrix;
    matrix->matrix.swapRows(i1, i2);
    matrix->update();
}


void MatrixButtons::on_addRowBtn_clicked()
{
    *lastMatrix = matrix->matrix;
    matrix->matrix.addRow();
    matrix->update();
}


void MatrixButtons::on_addColBtn_clicked()
{
    *lastMatrix = matrix->matrix;
    matrix->matrix.addColumn();
    matrix->update();
}

