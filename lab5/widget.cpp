#include <iostream>
#include "widget.h"
#include "ui_widget.h"
#include "model.h"

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
    Model model;


    auto start = chrono::system_clock::now();
    model.generate(300, 0.01);
    auto end = std::chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    double res = elapsed_seconds.count();
    cout << res << endl;
}
