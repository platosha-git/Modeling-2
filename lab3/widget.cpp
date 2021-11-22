#include "widget.h"
#include "ui_widget.h"
#include "generation.h"
#include <iostream>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void unmain()
{
    int n = 10;
    vector<int> vec1 = algGenerator(1, n);
    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;
}

void Widget::on_pushButton_clicked()
{
    unmain();
}
