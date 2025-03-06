// #include <iostream>
// using namespace std;

// // 基类
// class Base {
// public:
//     // 基类的构造函数
//     Base() {
//         cout << "Base constructor called." << endl;
//     }

//     // 基类的析构函数
//     ~Base() {
//         cout << "Base destructor called." << endl;
//     }
// };

// // 派生类
// class Derived : public Base {
// public:
//     // 派生类的构造函数
//     Derived() {
//         cout << "Derived constructor called." << endl;
//     }

//     // 派生类的析构函数
//     ~Derived() {
//         cout << "Derived destructor called." << endl;
//     }
// };

// int main() {
//     cout << "Creating an object of Derived class." << endl;
//     Derived obj;  // 创建派生类对象
//     cout << "Object created." << endl;

//     return 0;
// }


#include <iostream>
using namespace std;

// 基类
class Base {
public:
    Base(int x) {
        cout << "Base constructor with parameter: " << x << endl;
    }
};

// 派生类
class Derived : public Base {
public:
    Derived(int x, int y) : Base(x) {  // 显式调用基类构造函数
        cout << "Derived constructor with parameter: " << y << endl;
    }
};

int main() {
    Derived obj(10, 20);  // 创建派生类对象
    return 0;
}