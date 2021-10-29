#include <iostream>
#include "widget.h"
#include "ui_widget.h"
#include "memory.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStandardItemModel(2, 2, this);
    ui->Matrix->setModel(model);
    initMatrix(2);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initMatrix(const int numStates)
{
    for (int i = 0; i < numStates; i++) {
        ui->Matrix->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        QModelIndex index = model->index(i, i);
        model->setData(index, 0.0);
    }
}

void Widget::on_calculate_clicked()
{
    int numStates = ui->numStates->value();
    float **Matrix = nullptr;

    allocateMatrix(&Matrix, numStates);

    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numStates; j++) {
            QModelIndex index = model->index(i, j);
            Matrix[i][j] = model->data(index).toFloat();
        }
    }

    calculateTimeSystem(Matrix, numStates);

    freeMatrix(&Matrix, numStates);
}

void Widget::on_numStates_valueChanged(int arg1)
{
    model->setColumnCount(arg1);
    model->setRowCount(arg1);
    initMatrix(arg1);
}
