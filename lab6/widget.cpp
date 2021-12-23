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

    ui->lineNumClients->setText("300");
    ui->lineUnitTime->setText("0.01");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    Model model;

    int numClients = ui->lineNumClients->text().toInt();
    double unitTime = ui->lineUnitTime->text().toDouble();
    Result res = model.generate(numClients, unitTime);

    ui->lineServed->setText(QString::number(res.Service));
    ui->lineRefused->setText(QString::number(res.Refusals));
    ui->linePerRefused->setText(QString::number(res.PerRefusals));
}
