#include <iostream>
using namespace std;

/*
1. this 用于解决成员变量和成员函数参数同名时的歧义问题。
2. *this 是一个指针，指向调用成员函数的对象本身。
*/

class Point {
  private:
    int x;
    int y;

  public:
    Point(int x, int y) {
        this->x = x; // 使用 this 指针来区分成员变量和参数
        this->y = y;
        cout << this << endl;
    }
};

int main() {
    Point p1(1, 2);
    cout << &p1 << endl; // 输出对象 p1 的地址，应该与 this 指针的值相同

    Point p2(3, 4);
    cout << &p2 << endl; // 输出对象 p2 的地址，应该与 this 指针的值相同
}