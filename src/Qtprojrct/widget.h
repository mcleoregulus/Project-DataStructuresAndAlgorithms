#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Add_Button_clicked();

    void on_Delete_Button_clicked();

    void on_Delete_impedance_clicked();

    void on_Change_impedance_clicked();

    void on_analyseButton_clicked();

    void on_pushButton_2_clicked();

    void on_analyseButton_2_clicked();

    void on_importButton_clicked();

    void on_pushButton_clicked();

    void on_floydButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
