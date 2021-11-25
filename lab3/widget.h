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
    QStandardItemModel *modelAlg;
    QStandardItemModel *modelTab;

    void initTable(QTableView *table, const int numColumns);
    void outputModel(QStandardItemModel *model,
                     const std::vector<int> dig1,
                     const std::vector<int> dig2,
                     const std::vector<int> dig3);
};
#endif // WIDGET_H
