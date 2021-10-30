#include <iostream>
#include "widget.h"
#include "ui_widget.h"
#include "memory.h"
#include "calculations.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget)
{
    ui->setupUi(this);

    modelIn = new QStandardItemModel(10, 10, this);
    ui->Matrix->setModel(modelIn);
    initMatrix(10);

    modelOut = new QStandardItemModel(10, 2, this);
    ui->TimeTable->setModel(modelOut);
    initTimeTable(10);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initMatrix(const int numStates)
{
    ui->Matrix->clearSpans();
    for (int i = 0; i < numStates; i++) {
        ui->Matrix->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        QModelIndex index = modelIn->index(i, i);
        modelIn->setData(index, 0.0);
    }
}

void Widget::initTimeTable(const int numStates)
{
    ui->TimeTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    modelOut->setHeaderData(0, Qt::Horizontal, "Состояние");

    ui->TimeTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    modelOut->setHeaderData(1, Qt::Horizontal, "Время");

    for (int i = 0; i < numStates; i++) {
        QModelIndex index = modelOut->index(i, 0);
        QString state = QStringLiteral(" S %1").arg(i + 1);
        modelOut->setData(index, state);
    }
}

void Widget::outputTimeTable(vector<float> time, const int numStates)
{
    for (int i = 0; i < numStates; i++) {
        QModelIndex index = modelOut->index(i, 1);
        modelOut->setData(index, time[i]);
    }
}

void Widget::on_calculate_clicked()
{
    int numStates = ui->numStates->value();
    float **Matrix = nullptr;

    allocateMatrix(&Matrix, numStates);

    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numStates; j++) {
            QModelIndex index = modelIn->index(i, j);
            Matrix[i][j] = modelIn->data(index).toFloat();
        }
    }

    vector<float> time = calculateTimeSystem(Matrix, numStates);
    outputTimeTable(time, numStates);

    freeMatrix(&Matrix, numStates);
}

void Widget::on_numStates_valueChanged(int arg1)
{
    modelIn->setColumnCount(arg1);
    modelIn->setRowCount(arg1);
    initMatrix(arg1);

    modelOut->setRowCount(arg1);
    initTimeTable(arg1);
}
