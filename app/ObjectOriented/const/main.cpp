#include <iostream>
using namespace std;

class Hero {
  private:
    const int id; // 常量成员变量必须在构造函数的初始化列表中进行初始化
    int HP;
    int MP;

  public:
    Hero(int id, int hp, int mp) : id(id), HP(hp), MP(mp) {} // 使用初始化列表来初始化常量成员变量

    void display() const {
        cout << "Hero ID: " << id << ", HP: " << HP << ", MP: " << MP << endl;
    }

    int getId() const {
        return id; // 可以访问常量成员变量，但不能修改它
    }

    // 常量成员函数不能修改任何成员变量，包括常量成员变量
    int getHP() const {
        return HP;
    }

    int getMP() {
        return MP;
    }
};

int main() {
    Hero hero1(1, 100, 50);
    hero1.display();

    // hero1.id = 2; // 错误：不能修改常量成员变量
    // hero1.HP = 80; // 错误：不能修改常量成员变量

    cout << "Hero ID: " << hero1.getId() << endl;
    cout << "Hero HP: " << hero1.getHP() << endl;
    cout << "Hero MP: " << hero1.getMP() << endl;

    const Hero hero2(2, 150, 75); // 创建一个常量对象,只能调用常量成员函数
    hero2.display();
    cout << "Hero ID: " << hero2.getId() << endl;
    cout << "Hero HP: " << hero2.getHP() << endl;
    // cout << "Hero MP: " << hero2.getMP() << endl; // 错误：不能调用非常量成员函数

    return 0;
}