#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QTableWidget>

class MatrixWidget : public QTableWidget
{
    Q_OBJECT
public:
    MatrixWidget(QWidget *parent = nullptr);
    MatrixWidget(QSize, QWidget *parent = nullptr);
    MatrixWidget(QSize, QSize, QWidget *parent = nullptr);
    MatrixWidget(QSize, QPoint, QWidget *parent = nullptr);
    MatrixWidget(QSize, QPoint, QSize, QWidget *parent = nullptr);
    MatrixWidget(QSize, QRect, QWidget *parent = nullptr);

    MatrixWidget(const MatrixWidget &);

    void setPos(QPoint);
    void setSize(QSize);
    void setSizeMatrix(QSize);
    void setSizeMatrix(int, int);

private:
    QSize sizeMatrix;

};

#endif // MATRIXWIDGET_H
