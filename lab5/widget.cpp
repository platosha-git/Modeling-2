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

    ui->lineNumReq->setText("300");
    ui->lineUnitTime->setText("0.01");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    Model model;

    int numRequests = ui->lineNumReq->text().toInt();
    double unitTime = ui->lineUnitTime->text().toDouble();
    Result res = model.generate(numRequests, unitTime);

    ui->lineProcessed->setText(QString::number(res.Processed));
    ui->lineLost->setText(QString::number(res.Lost));
}
