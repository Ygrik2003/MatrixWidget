#include "matrixwidget.h"


MatrixWidget::MatrixWidget(QWidget *parent) : QTableWidget(parent)
{
    this->setSizeMatrix(1, 1);
}

MatrixWidget::MatrixWidget(QSize size, QWidget *parent) : QTableWidget(parent)
{
    this->setMinimumSize(size);
}

MatrixWidget::MatrixWidget(QSize sizeMatrix, QSize size, QWidget *parent) : QTableWidget(parent)
{
    this->setSizeMatrix(sizeMatrix);
    this->setSize(size);
}

MatrixWidget::MatrixWidget(QSize sizeMatrix, QPoint pos, QSize size, QWidget *parent) : QTableWidget(parent)
{
    this->setSizeMatrix(sizeMatrix);
    this->setGeometry(QRect(pos, size));
}

MatrixWidget::MatrixWidget(QSize sizeMatrix, QRect geometry, QWidget *parent) : QTableWidget(parent)
{
    this->setSizeMatrix(sizeMatrix);
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

