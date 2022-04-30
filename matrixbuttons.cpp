#include "matrixbuttons.h"
#include "ui_matrixbuttons.h"

MatrixButtons::MatrixButtons(Matrix &matrix, Matrix &lastMatrix, QWidget *parent) :
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
    ui->detLbl->setText("Determinant = " + QString::number(matrix->determinant()));
}


void MatrixButtons::on_calcAlgAddBtn_clicked()
{
    int i = ui->iEdit->text().toInt();
    int j = ui->jEdit->text().toInt();
    ui->algAddLbl->setText("AlgAdd = " + QString::number(matrix->algAddition(i, j)));
}

