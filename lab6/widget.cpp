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

    ui->lineFullTransf->setText(QString::number(res.FTransf));
    ui->lineHalfTransf->setText(QString::number(res.HTransf));

    QString str1 = "";
    for (auto len : res.LMaxLen) {
        str1 += QString::number(len) + " ";
    }
    ui->lineMaxLen1->setText(str1);

    QString str2 = "";
    for (auto len : res.HMaxLen) {
        str2 += QString::number(len) + " ";
    }
    ui->lineMaxLen2->setText(str2);
}
