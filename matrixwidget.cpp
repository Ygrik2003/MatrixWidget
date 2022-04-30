#include "matrixbuttons.h"
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


void MatrixWidget::setPos(QPoint pos)
{
    this->setGeometry(QRect(pos, this->size()));
}

void MatrixWidget::setSize(QSize size)
{
    this->setGeometry(QRect(this->pos(), size));
}

void MatrixWidget::update()
{
    this->setRowCount(matrix.size());
    this->setColumnCount(matrix.getRow(0).size());

    for (int i = 0; i < matrix.size(); i++) {
        this->setRowHeight(i, (size().height() - 1) / matrix.size());
        for (int j = 0; j < matrix.getRow(i).size(); j++)
        {
            this->setColumnWidth(j, (size().width() - 1) / matrix.getRow(i).size());
            if (!item(i, j))
                setItem(i, j, new QTableWidgetItem);

            item(i, j)->setText(QString::number(matrix.getElement(i, j)));
        }
    }
}

void MatrixWidget::checkDouble(int row, int column)
{
    bool check;
    double tmp = item(row, column)->text().toDouble(&check);
    if (check) {
        matrix.setElement(row, column, tmp);
    } else {
        item(row, column)->setText("0");
        item(row, column)->setTextAlignment(Qt::AlignCenter);
        item(row, column)->setFont(QFont("Helvetica", 20));


        matrix.setElement(row, column, 0);
    }
}

void MatrixWidget::mouseDoubleClickEvent(QMouseEvent *)
{
    MatrixButtons *mBtns = new MatrixButtons(*this, lastMatrix);
    mBtns->show();
}
