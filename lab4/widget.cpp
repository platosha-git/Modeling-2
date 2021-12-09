#include <iostream>
#include "widget.h"
#include "ui_widget.h"
#include "generator.h"

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


void Widget::on_pushButton_clicked()
{
    Generator gen;
    gen.setEvenDistribution(1, 10);
    gen.setNormalDistribution(4, 0.2);

    int len1 = gen.eventTime(1000, 0);
    cout << "len1 = " << len1 << endl;

    int len2 = gen.stepTime(1000, 0, 0.01);
    cout << "len2 = " << len2 << endl;
}
