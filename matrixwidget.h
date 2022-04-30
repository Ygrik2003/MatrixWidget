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

    void setPos(QPoint);
    void setSize(QSize);
    void buttonMenu();
    void update();
    Matrix matrix;

private:
    Matrix lastMatrix;
private slots:
    void checkDouble(int row, int column);



    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // MATRIXWIDGET_H
