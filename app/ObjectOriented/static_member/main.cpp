#include <iostream>
using namespace std;

class Hero {
  private:
    string name;
    int HP;

    // 静态成员变量，用于统计创建的 Hero 对象数量
    static int hero_count;

  public:
    Hero(string n = "Hero", int hp = 100) : name(n), HP(hp) {
        hero_count++;
    }

    // 静态成员函数，用于获取当前创建的 Hero 对象数量
    static int getHeroCount() {
        return hero_count;
    }
};

// 静态成员变量必须在类外进行定义和初始化
int Hero::hero_count = 0;

int main() {
    Hero hero1("Hero1", 150);
    Hero hero2("Hero2", 120);

    // 输出当前创建的 Hero 对象数量
    cout << "Total heroes created: " << Hero::getHeroCount() << endl;
    cout << hero1.getHeroCount() << endl; // 也可以通过对象调用静态成员函数

    return 0;
}