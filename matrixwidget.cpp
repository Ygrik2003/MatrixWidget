#include "matrixwidget.h"


MatrixWidget::MatrixWidget(QWidget *parent) : QTableWidget(parent)
{
    this->matrix.setSize(1, 1);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(this, &QTableWidget::cellChanged, this, &MatrixWidget::checkDouble);
    this->horizontalHeader()->hide();
    this->verticalHeader()->hide();
}

MatrixWidget::MatrixWidget(QSize size, QWidget *parent) : MatrixWidget(parent)
{
    this->setMinimumSize(size);
}

MatrixWidget::MatrixWidget(QSize sizeMatrix, QSize size, QWidget *parent) : MatrixWidget(parent)
{
    this->matrix.setSize(sizeMatrix);
    this->setSize(size);
}

MatrixWidget::MatrixWidget(QPoint pos, QSize size, QWidget *parent) : MatrixWidget(parent)
{
    this->setGeometry(QRect(pos, size));
}

MatrixWidget::MatrixWidget(QSize sizeMatrix, QPoint pos, QSize size, QWidget *parent) : MatrixWidget(pos, size, parent)
{
    this->matrix.setSize(sizeMatrix);
}

MatrixWidget::MatrixWidget(QSize sizeMatrix, QRect geometry, QWidget *parent) : MatrixWidget(parent)
{
    this->matrix.setSize(sizeMatrix);
    this->setGeometry(geometry);
}

void MatrixWidget::setPos(QPoint pos)
{
    this->setGeometry(QRect(pos, QSize(this->width(), this->height())));
}

void MatrixWidget::setSize(QSize size)
{
    this->setGeometry(QRect(QPoint(this->x(), this->y()), size));
}

void MatrixWidget::update()
{
    if (!matrix.size())
        throw MatrixException(MatrixException::errors::SizeError);
    this->setRowCount(matrix.size());
    this->setColumnCount(matrix[0].size());

    for (int i = 0; i < matrix.size(); i++) {
        this->setRowHeight(i, (size().height() - 1) / matrix.size());
        for (int j = 0; j < matrix[i].size(); j++)
        {
            this->setColumnWidth(j, (size().width() - 1) / matrix[i].size());
            if (!item(i, j))
                setItem(i, j, new QTableWidgetItem);

            item(i, j)->setText(QString::number(matrix[i][j]));
        }
    }
}

void MatrixWidget::checkDouble(int row, int column)
{
    bool check;
    double tmp = item(row, column)->text().toDouble(&check);
    if (check) {
        matrix[row][column] = tmp;
    } else {
        item(row, column)->setText("0");
        item(row, column)->setTextAlignment(Qt::AlignCenter);
        item(row, column)->setFont(QFont("Helvetica", 20));


        matrix[row][column] = 0;
    }
}
