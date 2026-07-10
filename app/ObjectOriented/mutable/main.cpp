#include <iostream>
using namespace std;

class Hero {
  private:
    int Hp;
    mutable int get_Hp_counter; // mutable 关键字允许在 const 函数中修改该成员变量

  public:
    static const int Max_Hp;

    Hero() : Hp(50), get_Hp_counter(0) {}

    int get_Hp() const {
        get_Hp_counter++;
        return Hp;
    }

    void show() const {
        cout << "Hero HP: " << Hp << ", get_Hp called: " << get_Hp_counter << " times" << endl;
    }
};

const int Hero::Max_Hp = 100; // 定义和初始化静态常量成员变量

int main() {
    const Hero hero;                              // 创建一个常量对象
    hero.show();                                  // 输出初始状态
    cout << "Hero HP: " << hero.get_Hp() << endl; // 调用 const 成员函数，修改 mutable 变量
    hero.show();                                  // 输出修改后的状态，get_Hp_counter 应该增加了

    cout << Hero::Max_Hp << endl; // 访问静态常量成员变量
}