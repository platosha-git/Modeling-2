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
    vector<int> vec1 = algGenerator(n, 1, 9);
    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    vector<int> vec2 = algGenerator(n, 10, 99);
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;

    vector<int> vec3 = algGenerator(n, 100, 999);
    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3[i] << " ";
    }
    cout << endl;

    vector<int> vec4 = tableGenerator(n, 1, 9);
    for (int i = 0; i < vec4.size(); i++) {
        cout << vec4[i] << " ";
    }
    cout << endl;
}

void Widget::on_pushButton_clicked()
{
    unmain();
}
