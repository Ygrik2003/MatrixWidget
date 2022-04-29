#include "matrixwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixWidget w(QSize(4, 3), QPoint(0, 0), QSize(500, 500));
    w.update();
    w.show();
    return a.exec();
}
