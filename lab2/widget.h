#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QVector>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_calculate_clicked();
    void on_numStates_valueChanged(int arg1);

private:
    Ui::Widget *ui;
    QStandardItemModel *modelIn;
    QStandardItemModel *modelOut;
    QCPGraph *graphic;

    void initMatrix(const int numStates);

    void initTimeTable();
    void outputTimeTable(std::vector<double> p, std::vector<double> time, const int numStates);
    void plotGraphics(std::vector<double> dP, std::vector<double> dTime, const int numStates);
};
#endif // WIDGET_H
