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
    void scrollBarVisibility(bool);
    Matrix matrix;

private:
    Matrix lastMatrix;
private slots:
    void checkDouble(int row, int column);



    // QWidget interface
protected:
    void mouseDoubleClickEvent(QMouseEvent *) override;
    void timerEvent(QTimerEvent *event) override;
};

#endif // MATRIXWIDGET_H
