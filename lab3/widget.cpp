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

    modelAlg = new QStandardItemModel(10, 3, this);
    modelTab = new QStandardItemModel(10, 3, this);

    ui->tableAlg->setModel(modelAlg);
    ui->tableTab->setModel(modelTab);

    initTable(ui->tableAlg, 3);
    initTable(ui->tableTab, 3);
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

void Widget::outputModel(QStandardItemModel *model,
                         const vector<int> dig1,
                         const vector<int> dig2,
                         const vector<int> dig3)
{
    for (int i = 0; i < NumRows; i++) {
        QModelIndex index1 = model->index(i, 0);
        QModelIndex index2 = model->index(i, 1);
        QModelIndex index3 = model->index(i, 2);

        model->setData(index1, dig1[i]);
        model->setData(index2, dig2[i]);
        model->setData(index3, dig3[i]);
    }
}

void Widget::on_generate_clicked()
{
    vector<int> alg1 = algGenerator(N, 1, 9);
    vector<int> alg2 = algGenerator(N, 10, 99);
    vector<int> alg3 = algGenerator(N, 100, 999);
    outputModel(modelAlg, alg1, alg2, alg3);

    vector<int> tab1 = tabGenerator(N, 1, 9);
    vector<int> tab2 = tabGenerator(N, 10, 99);
    vector<int> tab3 = tabGenerator(N, 100, 999);
    outputModel(modelTab, tab1, tab2, tab3);
}

void Widget::on_input_clicked()
{
    QString userVecQStr = ui->lineUser->text();
    string userVecStr = userVecQStr.toStdString();

    vector<int> user;
    istringstream ss(userVecStr);
    copy(istream_iterator<int>(ss), {}, back_inserter(user));
}
