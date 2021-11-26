#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "widget.h"
#include "ui_widget.h"
#include "generation.h"

const int NumRows = 10;
const int N = 1000;
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    modelAlgIn = new QStandardItemModel(10, 3, this);
    modelTabIn = new QStandardItemModel(10, 3, this);

    modelAlgOut = new QStandardItemModel(2, 3, this);
    modelTabOut = new QStandardItemModel(2, 3, this);

    ui->tableAlgIn->setModel(modelAlgIn);
    ui->tableTabIn->setModel(modelTabIn);

    ui->tableAlgOut->setModel(modelAlgOut);
    ui->tableTabOut->setModel(modelTabOut);

    initTable(ui->tableAlgIn, 3);
    initTable(ui->tableTabIn, 3);

    initTable(ui->tableAlgOut, 3);
    initTable(ui->tableTabOut, 3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initTable(QTableView *table, const int numColumns)
{
    table->clearSpans();

    for (int i = 0; i < numColumns; i++) {
        table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }
}

void Widget::outputModel(QStandardItemModel *model, const int numRows,
                         const vector<int> dig1,
                         const vector<int> dig2,
                         const vector<int> dig3)
{
    for (int i = 0; i < numRows; i++) {
        QModelIndex index1 = model->index(i, 0);
        QModelIndex index2 = model->index(i, 1);
        QModelIndex index3 = model->index(i, 2);

        model->setData(index1, dig1[i]);
        model->setData(index2, dig2[i]);
        model->setData(index3, dig3[i]);
    }
}

void Widget::outputModel(QStandardItemModel *model,
                         const vector<double> resActual, const vector<double> resTheory)
{
    QModelIndex index1 = model->index(0, 0);
    QModelIndex index2 = model->index(0, 1);
    QModelIndex index3 = model->index(0, 2);

    model->setData(index1, resActual[0]);
    model->setData(index2, resActual[1]);
    model->setData(index3, resActual[2]);

    index1 = model->index(1, 0);
    index2 = model->index(1, 1);
    index3 = model->index(1, 2);

    model->setData(index1, resTheory[0]);
    model->setData(index2, resTheory[1]);
    model->setData(index3, resTheory[2]);
}

void Widget::on_generate_clicked()
{
    vector<int> alg1 = algGenerator(N, 1, 9);
    vector<int> alg2 = algGenerator(N, 10, 99);
    vector<int> alg3 = algGenerator(N, 100, 999);
    outputModel(modelAlgIn, NumRows, alg1, alg2, alg3);

    vector<int> tab1 = tabGenerator(N, 1, 9);
    vector<int> tab2 = tabGenerator(N, 10, 99);
    vector<int> tab3 = tabGenerator(N, 100, 999);
    outputModel(modelTabIn, NumRows, tab1, tab2, tab3);

    vector<vector<double>> critAlg = criterionCheck(alg1, alg2, alg3);
    outputModel(modelAlgOut, critAlg[0], critAlg[1]);

    vector<vector<double>> critTab = criterionCheck(tab1, tab2, tab3);
    outputModel(modelTabOut, critTab[0], critTab[1]);
}

void Widget::on_input_clicked()
{
    QString userVecQStr = ui->lineUser->text();
    string userVecStr = userVecQStr.toStdString();

    vector<int> user;
    istringstream ss(userVecStr);
    copy(istream_iterator<int>(ss), {}, back_inserter(user));

    vector<double> critUser = frequencyTest(user, 0, 10);
    QString res = QString::number(critUser[0]) + "\n" + QString::number(critUser[1]);
    ui->textUser->setText(res);
}
