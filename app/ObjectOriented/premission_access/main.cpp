#include <iostream>
using namespace std;

// 访问权限修饰符：public、private、protected
// public：公共的，类内外都可以访问
// private：私有的，类内可以访问，类外不可以访问
// protected：受保护的，类内可以访问，类外不可以访问，但子类可以访问

/*
B -> A

A 是父类（基类、超类）
B 是子类（派生类）

子类继承了父类的成员属性和成员行为，但不能访问父类的private成员。
子类可以访问父类的public和protected成员。
*/

class People {
  public:
    int m_Id;

    // protected成员
  protected:
    int m_house_Id;

    // private成员
  private:
    int m_pay_password;

  public:
    void work() {
        // 在类的成员函数中可以访问所有成员，包括private和protected成员
        m_Id = 1;
        m_house_Id = 2;          // protected成员可以访问
        m_pay_password = 123456; // private成员可以访问
    }
};

class son : public People {
  public:
    void play() {
        m_Id = 1;       // public成员可以访问
        m_house_Id = 2; // protected成员可以访问
        // m_pay_password = 123456; // private成员不能访问
    }
};

int main() {
    People p;
    p.m_Id = 1001; // public成员可以访问
    // p.m_house_Id = 1002; // protected成员不能访问
    // p.m_pay_password = 123456; // private成员不能访问

    p.work(); // 调用work函数来访问private和protected成员
}