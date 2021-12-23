/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QFrame *line;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelA_3;
    QLineEdit *lineServed;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelA_4;
    QLineEdit *lineRefused;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelA_5;
    QLineEdit *linePerRefused;
    QFrame *line_2;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelA_7;
    QLineEdit *lineNumClients;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelA_8;
    QLineEdit *lineUnitTime;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(451, 417);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 431, 401));
        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 180, 441, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 210, 301, 181));
        horizontalLayoutWidget_4 = new QWidget(groupBox_3);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 30, 281, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelA_3 = new QLabel(horizontalLayoutWidget_4);
        labelA_3->setObjectName(QString::fromUtf8("labelA_3"));

        horizontalLayout_4->addWidget(labelA_3);

        lineServed = new QLineEdit(horizontalLayoutWidget_4);
        lineServed->setObjectName(QString::fromUtf8("lineServed"));

        horizontalLayout_4->addWidget(lineServed);

        horizontalLayoutWidget_5 = new QWidget(groupBox_3);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 80, 281, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        labelA_4 = new QLabel(horizontalLayoutWidget_5);
        labelA_4->setObjectName(QString::fromUtf8("labelA_4"));

        horizontalLayout_5->addWidget(labelA_4);

        lineRefused = new QLineEdit(horizontalLayoutWidget_5);
        lineRefused->setObjectName(QString::fromUtf8("lineRefused"));

        horizontalLayout_5->addWidget(lineRefused);

        horizontalLayoutWidget_6 = new QWidget(groupBox_3);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 130, 281, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        labelA_5 = new QLabel(horizontalLayoutWidget_6);
        labelA_5->setObjectName(QString::fromUtf8("labelA_5"));

        horizontalLayout_6->addWidget(labelA_5);

        linePerRefused = new QLineEdit(horizontalLayoutWidget_6);
        linePerRefused->setObjectName(QString::fromUtf8("linePerRefused"));

        horizontalLayout_6->addWidget(linePerRefused);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 190, 441, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        horizontalLayoutWidget_8 = new QWidget(widget);
        horizontalLayoutWidget_8->setObjectName(QString::fromUtf8("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(10, 10, 231, 41));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        labelA_7 = new QLabel(horizontalLayoutWidget_8);
        labelA_7->setObjectName(QString::fromUtf8("labelA_7"));

        horizontalLayout_8->addWidget(labelA_7);

        lineNumClients = new QLineEdit(horizontalLayoutWidget_8);
        lineNumClients->setObjectName(QString::fromUtf8("lineNumClients"));

        horizontalLayout_8->addWidget(lineNumClients);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 120, 411, 51));
        horizontalLayoutWidget_9 = new QWidget(widget);
        horizontalLayoutWidget_9->setObjectName(QString::fromUtf8("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(10, 60, 231, 41));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        labelA_8 = new QLabel(horizontalLayoutWidget_9);
        labelA_8->setObjectName(QString::fromUtf8("labelA_8"));

        horizontalLayout_9->addWidget(labelA_8);

        lineUnitTime = new QLineEdit(horizontalLayoutWidget_9);
        lineUnitTime->setObjectName(QString::fromUtf8("lineUnitTime"));

        horizontalLayout_9->addWidget(lineUnitTime);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        groupBox_3->setTitle(QApplication::translate("Widget", "Results", nullptr));
        labelA_3->setText(QApplication::translate("Widget", "Served clients:", nullptr));
        labelA_4->setText(QApplication::translate("Widget", "Refuses clients:", nullptr));
        labelA_5->setText(QApplication::translate("Widget", "Refuses percentage:", nullptr));
        labelA_7->setText(QApplication::translate("Widget", "Number of clients:", nullptr));
        pushButton->setText(QApplication::translate("Widget", "Generate", nullptr));
        labelA_8->setText(QApplication::translate("Widget", "Unit of time:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
