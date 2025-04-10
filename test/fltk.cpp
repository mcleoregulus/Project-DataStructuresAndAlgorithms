#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>

// 回调函数
void button_callback(Fl_Widget *widget, void *data) {
    std::cout << "Button Clicked!" << std::endl;
}

int main(int argc, char **argv) {
    // 创建一个窗口
    Fl_Window *window = new Fl_Window(400, 300, "FLTK Button Example");

    // 创建一个按钮
    Fl_Button *button = new Fl_Button(160, 220, 80, 40, "Click Me");
    button->callback(button_callback); // 绑定回调函数

    // 显示窗口
    window->show();
    return Fl::run();
}