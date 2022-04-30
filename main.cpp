#include "matrixwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixWidget w;
    w.setGeometry(0, 0, 500, 500);
    w.matrix.setSize(3, 3);
    w.update();
    w.show();
    return a.exec();
}
