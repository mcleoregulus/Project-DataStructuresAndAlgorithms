#include <iostream>
#include <complex>  // 包含复数类
using namespace std;

int main() {
    // 创建复数
    complex<double> c1(3.0, 4.0);  // 实部为3.0，虚部为4.0
    complex<double> c2(1.0, 2.0);  // 实部为1.0，虚部为2.0

    // 复数运算
    complex<double> sum = c1 + c2;  // 加法
    complex<double> diff = c1 - c2; // 减法
    complex<double> prod = c1 * c2; // 乘法
    complex<double> quot = c1 / c2; // 除法

    // 输出结果
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << prod << endl;
    cout << "c1 / c2 = " << quot << endl;

    // 获取复数的模和幅角
    double modulus = abs(c1);  // 模
    double argument = arg(c1); // 幅角（弧度）
    cout << "Modulus of c1 = " << modulus << endl;
    cout << "Argument of c1 = " << argument << " radians" << endl;

    return 0;
}


// int main() {
//     double modulus = 5.0;  // 模
//     double argument = 0.9273;  // 幅角（弧度）

//     // 构造复数
//     complex<double> c = polar(modulus, argument);

//     cout << "Complex number in rectangular form: " << c << endl;
//     cout << "Modulus: " << abs(c) << endl;
//     cout << "Argument: " << arg(c) << " radians" << endl;

//     return 0;
// }

