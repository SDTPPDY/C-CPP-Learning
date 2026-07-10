#include <iostream>
using namespace std;

class list {
  private:
    int ID;

  public:
    list(int id = 0) : ID(id) {
        cout << "调用了list的构造函数" << endl;
        cout << "创建了list对象，ID: " << ID << endl;
    }

    ~list() {
        cout << "调用了list的析构函数" << endl;
        cout << "销毁了list对象，ID: " << ID << endl;
    }
};

void func() {
    list tempList(2); // 创建一个临时list对象，调用构造函数
    // 当func函数结束时，tempList对象会被销毁，调用析构函数
}

int main() {
    list myList(1); // 创建一个list对象，调用构造函数

    func(); // 调用func函数，创建并销毁临时对象

    for (int i = 0; i < 3; i++) {
        list loopList(i + 3); // 在循环中创建多个list对象，调用构造函数
        // 当每次循环结束时，loopList对象会被销毁，调用析构函数
    }

    // 当main函数结束时，myList对象会被销毁，调用析构函数
    return 0;
}