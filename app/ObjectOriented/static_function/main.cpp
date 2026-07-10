#include <iostream>
using namespace std;

/*
静态成员函数（Static Member Function）是属于类而不是对象的函数，可以在没有创建对象的情况下调用。静态成员函数只能访问静态成员变量，不能访问非静态成员变量，因为它们不依赖于任何对象实例。

静态成员函数的特点：
1. 属于类而不是对象，可以直接通过类名调用。
2. 只能访问静态成员变量，不能访问非静态成员变量。
3. 可以被对象调用，但不推荐，因为它们不依赖于对象实例。
4. 在静态成员函数中，不能使用 this 指针，因为它们不属于任何对象实例。

*/

class Hero {
  private:
    string name;
    int HP;

    static int hero_count;

    static void incrementHeroCount() {
        hero_count++;
    }

  public:
    Hero() {
        name = "Hero";
        HP = 100;
        hero_count++;
    }

    static int getHeroCount() {
        return hero_count;
    }
};

int Hero::hero_count = 0;

int main() {
    Hero hero1;
    Hero hero2;

    cout << "Total heroes created: " << Hero::getHeroCount() << endl;
    cout << "Total heroes created (using object): " << hero1.getHeroCount() << endl;

    // Hero::incrementHeroCount(); // 错误：无法访问私有静态成员函数
    return 0;
}