#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>

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

    void initMatrix(const int numStates);
    void initTimeTable(const int numStates);
    void outputTimeTable(std::vector<float> time, const int numStates);
};
#endif // WIDGET_H
