// #include <QWidget>
// #include <QPainter>
// #include <QApplication>

// class MyWidget : public QWidget
// {
// protected:
//     void paintEvent(QPaintEvent* event) override
//     {
//         QPainter painter(this); // 创建一个 QPainter 对象
//         painter.setPen(Qt::black); // 设置画笔颜色为黑色
//         painter.drawLine(10, 10, 100, 100); // 绘制一条从 (10, 10) 到 (100, 100) 的线
//     }
// };

// int main(int argc, char* argv[])
// {
//     QApplication app(argc, argv);

//     MyWidget widget;
//     widget.resize(200, 200); // 设置窗口大小
//     widget.setWindowTitle("Draw Line Example");
//     widget.show();

//     return app.exec();
// }

#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QGraphicsView view; // 创建一个 QGraphicsView
    QGraphicsScene scene; // 创建一个 QGraphicsScene
    view.setScene(&scene); // 将场景关联到视图

    QGraphicsLineItem* line = scene.addLine(10, 10, 100, 100); // 在场景中添加一条线
    line->setPen(QPen(Qt::black, 2)); // 设置线的颜色和宽度

    view.setWindowTitle("Draw Line Example");
    view.resize(200, 200);
    view.show();

    return app.exec();
}