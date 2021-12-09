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
    int numMsg = ui->lineNumMsg->text().toInt();
    Generator gen(numMsg);

    float a = ui->lineA->text().toFloat();
    float b = ui->lineB->text().toFloat();
    gen.setEvenDistribution(a, b);

    float lambda = ui->lineLambda->text().toFloat();
    gen.setPoissonDistribution(lambda);

    int lenEvent = gen.eventTime();
    ui->lineEvent->setText(QString::number(lenEvent));

    double step = ui->lineStep->text().toDouble();
    int lenIteration = gen.iterTime(step);
    ui->lineIteration->setText(QString::number(lenIteration));
}
