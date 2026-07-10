#include <iostream>
using namespace std;

/*
友元的目的：
让一个 类 或者 函数 能够访问另一个类的私有成员变量和私有成员函数。

关键字：friend

三种友元：
1. 友元函数：一个普通的函数，可以访问类的私有成员变量和私有成员函数。
2. 友元类：一个类的所有成员函数都可以访问另一个类的私有成员变量和私有成员函数。
3. 友元成员函数：一个类的某个成员函数可以访问另一个类的私有成员变量和私有成员函数。
*/

class People; // 前向声明，告诉编译器People类的存在

class PeopleFriend {
  public:
    void visit(const People& person);
};

class People {
    friend void introduce(const People& person); // 声明友元函数，可以访问私有成员变量
    friend class PeopleFriend;                   // 声明友元类，PeopleFriend的所有成员函数都可以访问私有成员变量
  private:
    string name;
    int age;

  public:
    People(string name, int age) : name(name), age(age) {}
};

void introduce(const People& person) {
    cout << "Hello, my name is " << person.name << " and I am " << person.age << " years old." << endl;
}

void PeopleFriend::visit(const People& person) {
    cout << "Visiting " << person.name << " who is " << person.age << " years old." << endl;
}

int main() {
    People person("Alice", 30);
    introduce(person); // 调用友元函数，访问私有成员变量
    PeopleFriend frd;
    frd.visit(person); // 调用友元类的成员函数，访问私有成员变量
    return 0;
}