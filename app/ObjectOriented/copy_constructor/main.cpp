#include <iostream>
using namespace std;

class Hero {
  private:
    int HP;
    int skill_count;
    int speed;

  public:
    Hero(int hp = 100, int skill = 5, int spd = 10) : HP(hp), skill_count(skill), speed(spd) {}

    // Copy constructor
    // 一定要写成 const Hero &other 的形式
    Hero(const Hero& other) : HP(other.HP), skill_count(other.skill_count), speed(other.speed) {
        cout << "Copy constructor called!" << endl;
    }
};

int main() {
    Hero hero1(150, 10, 20); // 创建一个 Hero 对象
    Hero hero2 = hero1;      // 使用复制构造函数创建 hero2

    return 0;
}