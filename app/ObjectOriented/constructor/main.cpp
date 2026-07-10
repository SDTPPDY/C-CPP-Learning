#include <iostream>
using namespace std;

class Hero {
  private:
    string name;
    int HP;
    int skill_count;

  public:
    // 构造函数，提供默认参数
    Hero(string n = "Hero", int hp = 100, int skill = 5) {
        name = n;
        HP = hp;
        skill_count = skill;
        cout << "调用了构造函数，创建了英雄: " << name << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "HP: " << HP << endl;
        cout << "Skill Count: " << skill_count << endl;
    }
};


int main() {
    Hero hero1; // 使用默认参数创建英雄
    hero1.display();

    cout << endl;

    Hero hero2("Warrior", 150, 10); // 使用自定义参数创建英雄
    hero2.display();

    return 0;
}