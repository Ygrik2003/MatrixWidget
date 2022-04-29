#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include "matrix.h"
#include <QTableWidget>
#include <QHeaderView>

class MatrixWidget : public QTableWidget
{
    Q_OBJECT
public:
    MatrixWidget(QWidget *parent = nullptr);
    MatrixWidget(QSize size, QWidget *parent = nullptr);
    MatrixWidget(QPoint pos, QSize size, QWidget *parent = nullptr);
    MatrixWidget(QSize sizeMatrix, QSize size, QWidget *parent = nullptr);
    MatrixWidget(QSize sizeMatrix, QPoint pos, QSize size, QWidget *parent = nullptr);
    MatrixWidget(QSize sizeMatrix, QRect geometry, QWidget *parent = nullptr);


    void setPos(QPoint);
    void setSize(QSize);
    void update();
    Matrix matrix;

private slots:
    void checkDouble(int row, int column);


};

#endif // MATRIXWIDGET_H
