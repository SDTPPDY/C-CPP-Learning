#include <iostream>
using namespace std;

// 面向对象三大特征：封装、继承、多态

/*
封装的语法：

class 类名 {
    访问权限修饰符:
        成员属性（成员对象）;
        成员行为（成员函数）;
};
*/

class Hero {
    // 访问权限修饰符：public、private、protected
  public:
    // 成员属性（成员对象）
    int m_Id; // m -> member
    int m_HP;

    // 成员行为（成员函数）
    void add_HP(int hp) {
        m_HP += hp;
    }
    void sub_HP(int hp) {
        m_HP -= hp;
    }
};

int main() {
    // 创建英雄对象
    // 通过类来创建对象的过程叫做实例化，创建出来的对象叫做类的实例
    Hero h1;

    // 访问对象的属性
    h1.m_Id = 1001;
    h1.m_HP = 100;

    cout << "英雄ID：" << h1.m_Id << endl;
    cout << "英雄HP：" << h1.m_HP << endl;

    // 访问对象的行为
    // 英雄吃药
    h1.add_HP(20);
    cout << "吃药后英雄HP：" << h1.m_HP << endl;

    // 英雄受伤
    h1.sub_HP(50);
    cout << "受伤后英雄HP：" << h1.m_HP << endl;

    return 0;
}