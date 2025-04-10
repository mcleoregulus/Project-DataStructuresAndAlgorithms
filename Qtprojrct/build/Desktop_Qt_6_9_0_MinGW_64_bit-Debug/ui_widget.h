/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <paintwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_17;
    paintwidget *graphWidget;
    QSpacerItem *horizontalSpacer_18;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *importButton;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_23;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *Add_Button;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_4;
    QLineEdit *Delete_txt;
    QPushButton *Delete_Button;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_5;
    QLineEdit *Bus_txt1;
    QLineEdit *Bus_txt2;
    QPushButton *Delete_impedance;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *Resistance_txt;
    QLabel *label_8;
    QLineEdit *Reactance_txt;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Change_impedance;
    QSpacerItem *horizontalSpacer_4;
    QSplitter *splitter;
    QLabel *label_10;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *analyseButton;
    QPushButton *analyseButton_2;
    QPushButton *floydButton;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(880, 672);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 30, 741, 401));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget);
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_15);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_8->addWidget(label_9);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_16);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_17);

        graphWidget = new paintwidget(layoutWidget);
        graphWidget->setObjectName("graphWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphWidget->sizePolicy().hasHeightForWidth());
        graphWidget->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(graphWidget);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_18);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 9);
        horizontalLayout_9->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_9);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 12);

        horizontalLayout_10->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        verticalLayout->addWidget(label_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_24);

        importButton = new QPushButton(layoutWidget);
        importButton->setObjectName("importButton");

        horizontalLayout_12->addWidget(importButton);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_12->addWidget(pushButton);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_23);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_7->addWidget(label_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        Add_Button = new QPushButton(layoutWidget);
        Add_Button->setObjectName("Add_Button");

        horizontalLayout->addWidget(Add_Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        Delete_txt = new QLineEdit(layoutWidget);
        Delete_txt->setObjectName("Delete_txt");

        horizontalLayout_2->addWidget(Delete_txt);

        Delete_Button = new QPushButton(layoutWidget);
        Delete_Button->setObjectName("Delete_Button");

        horizontalLayout_2->addWidget(Delete_Button);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_6->addWidget(label_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_11 = new QSpacerItem(13, 22, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        Bus_txt1 = new QLineEdit(layoutWidget);
        Bus_txt1->setObjectName("Bus_txt1");

        horizontalLayout_3->addWidget(Bus_txt1);

        Bus_txt2 = new QLineEdit(layoutWidget);
        Bus_txt2->setObjectName("Bus_txt2");

        horizontalLayout_3->addWidget(Bus_txt2);

        Delete_impedance = new QPushButton(layoutWidget);
        Delete_impedance->setObjectName("Delete_impedance");

        horizontalLayout_3->addWidget(Delete_impedance);

        horizontalSpacer_12 = new QSpacerItem(13, 22, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_4->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        Resistance_txt = new QLineEdit(layoutWidget);
        Resistance_txt->setObjectName("Resistance_txt");

        horizontalLayout_4->addWidget(Resistance_txt);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_4->addWidget(label_8);

        Reactance_txt = new QLineEdit(layoutWidget);
        Reactance_txt->setObjectName("Reactance_txt");

        horizontalLayout_4->addWidget(Reactance_txt);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_14);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 2);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 2);
        horizontalLayout_4->setStretch(6, 1);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        Change_impedance = new QPushButton(layoutWidget);
        Change_impedance->setObjectName("Change_impedance");

        horizontalLayout_5->addWidget(Change_impedance);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);

        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Vertical);
        label_10 = new QLabel(splitter);
        label_10->setObjectName("label_10");
        splitter->addWidget(label_10);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName("layoutWidget1");
        horizontalLayout_11 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_19);

        analyseButton = new QPushButton(layoutWidget1);
        analyseButton->setObjectName("analyseButton");

        horizontalLayout_11->addWidget(analyseButton);

        analyseButton_2 = new QPushButton(layoutWidget1);
        analyseButton_2->setObjectName("analyseButton_2");

        horizontalLayout_11->addWidget(analyseButton_2);

        floydButton = new QPushButton(layoutWidget1);
        floydButton->setObjectName("floydButton");

        horizontalLayout_11->addWidget(floydButton);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_20);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_11->addWidget(pushButton_2);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_21);

        splitter->addWidget(layoutWidget1);

        verticalLayout->addWidget(splitter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 1);
        verticalLayout->setStretch(6, 1);
        verticalLayout->setStretch(7, 1);
        verticalLayout->setStretch(8, 1);
        verticalLayout->setStretch(9, 1);
        verticalLayout->setStretch(10, 1);
        verticalLayout->setStretch(11, 1);

        horizontalLayout_10->addLayout(verticalLayout);

        horizontalLayout_10->setStretch(0, 3);
        horizontalLayout_10->setStretch(1, 1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\347\224\265\350\267\257\346\213\223\346\211\221\347\273\223\346\236\204\345\233\276\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "----------------------------\345\257\274\345\205\245\345\257\274\345\207\272----------------------------", nullptr));
        importButton->setText(QCoreApplication::translate("Widget", "\345\257\274\345\205\245CSV", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\257\274\345\207\272\344\270\272CSV", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "----------------------------\350\212\202\347\202\271\347\274\226\350\276\221----------------------------", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\350\212\202\347\202\271\350\207\252\345\212\250\347\274\226\345\217\267", nullptr));
        Add_Button->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\350\212\202\347\202\271", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244\350\212\202\347\202\271\347\274\226\345\217\267\357\274\232", nullptr));
        Delete_txt->setText(QString());
        Delete_Button->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244\350\212\202\347\202\271", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "----------------------------\351\230\273\346\212\227\347\274\226\350\276\221----------------------------", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\351\230\273\346\212\227\344\270\244\347\253\257\350\212\202\347\202\271\347\274\226\345\217\267\357\274\232", nullptr));
        Bus_txt1->setText(QString());
        Bus_txt2->setText(QString());
        Delete_impedance->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244\351\230\273\346\212\227", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\351\230\273\346\212\227(\346\254\247\345\247\206\357\274\211\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "R\357\274\232", nullptr));
        Resistance_txt->setText(QString());
        label_8->setText(QCoreApplication::translate("Widget", "X\357\274\232", nullptr));
        Reactance_txt->setText(QString());
        Change_impedance->setText(QCoreApplication::translate("Widget", "\346\233\264\346\224\271\351\230\273\346\212\227", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "----------------------------\347\224\265\350\267\257\345\210\206\346\236\220----------------------------", nullptr));
        analyseButton->setText(QCoreApplication::translate("Widget", "\350\212\202\347\202\271V", nullptr));
        analyseButton_2->setText(QCoreApplication::translate("Widget", "\346\224\257\350\267\257I,P", nullptr));
        floydButton->setText(QCoreApplication::translate("Widget", "Floyd", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\351\232\220\350\227\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
