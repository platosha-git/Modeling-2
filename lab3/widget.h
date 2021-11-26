#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableView>
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
    void on_generate_clicked();

    void on_input_clicked();

private:
    Ui::Widget *ui;
    QStandardItemModel *modelAlgIn;
    QStandardItemModel *modelTabIn;

    QStandardItemModel *modelAlgOut;
    QStandardItemModel *modelTabOut;

    void initTable(QTableView *table, const int numColumns);
    void outputModel(QStandardItemModel *model, const int numRows,
                     const std::vector<int> dig1,
                     const std::vector<int> dig2,
                     const std::vector<int> dig3);
    void outputModel(QStandardItemModel *model,
                     const std::vector<double> resActual, const std::vector<double> resTheory);
};
#endif // WIDGET_H
