
#include "../include/LList.hpp"
#include "../include/Graphl.hpp"

#include <iostream>
using namespace std;

// int main() {
//     LList<int> list;

//     list.append(10);
//     list.append(20);
//     list.append(30);

//     // 使用 getHead() 获取头指针并遍历链表
//     Link<int>* current = list.getHead();
//     while (current->next != NULL) {
//         cout << current->next->element << " ";
//         current = current->next;
//     }
//     cout << endl;

//     // 使用 getCurr() 获取当前指针并遍历链表
//     list.moveToStart();
//     current = list.getCurr();
//     while (current->next != NULL) {
//         cout << current->next->element << " ";
//         current = current->next;
//     }
//     cout << endl;

//     list.clear();

//     return 0;
// }


int main() {
    LList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.moveToStart();
    int length = list.length();

    for (int i = 0; i < length; i++) {
        cout << list.getValue() << " ";
        list.next();
    }
    cout << endl;

    // for (int i = 0; i < length; i++) {
    //     cout << list.getElementAt(i) << " ";
    // }
    // cout << endl;


    list.clear();

    return 0;
}