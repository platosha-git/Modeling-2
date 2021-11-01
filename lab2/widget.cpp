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
    initTimeTable();
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

void Widget::initTimeTable()
{
    ui->TimeTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    modelOut->setHeaderData(0, Qt::Horizontal, "Вероятность");

    ui->TimeTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    modelOut->setHeaderData(1, Qt::Horizontal, "Время");
}

void Widget::outputTimeTable(vector<double> p, vector<double> time, const int numStates)
{
    for (int i = 0; i < numStates; i++) {
        QModelIndex index = modelOut->index(i, 0);
        modelOut->setData(index, p[i]);

        index = modelOut->index(i, 1);
        modelOut->setData(index, time[i]);
    }
}

void Widget::plotGraphics(std::vector<double> dP, std::vector<double> dTime, const int numStates)
{
    QVector<double> x, y;
    ui->widget->clearGraphs();
    for (int i = 0; i < numStates; i++) {
        x.clear(); y.clear();

        for (int j = i; j < dP.size(); j += numStates) {
            x.push_back(dTime[j]);
            y.push_back(dP[j]);
        }

        ui->widget->addGraph();
        ui->widget->graph(i)->setData(x, y);
        QString name = QStringLiteral("S %1").arg(i + 1);
        ui->widget->graph(i)->setName(name);
        ui->widget->graph(i)->setPen(QPen(QColor(i * 100, 0, 0, 255), 0.6, Qt::PenStyle::SolidLine));
        ui->widget->xAxis->setLabel("t");
        ui->widget->xAxis->setRange(0, 5);
        ui->widget->yAxis->setLabel("P(t)");
        ui->widget->yAxis->setRange(0, 1.1);
        ui->widget->legend->setVisible(true);
        ui->widget->replot();
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

    Pt pt;
    pt = calculateTimeSystem(Matrix, numStates);
    outputTimeTable(pt.P, pt.Time, numStates);
    plotGraphics(pt.dP, pt.dTime, numStates);

    freeMatrix(&Matrix, numStates);
}

void Widget::on_numStates_valueChanged(int arg1)
{
    modelIn->setColumnCount(arg1);
    modelIn->setRowCount(arg1);
    initMatrix(arg1);

    modelOut->setRowCount(arg1);
}
