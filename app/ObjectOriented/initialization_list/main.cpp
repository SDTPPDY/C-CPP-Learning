#include <iostream>
using namespace std;

class Hero {
  private:
    int HP;
    int skill_count;
    int speed;

  public:
    // Constructor with initialization list
    Hero(int hp = 100, int skill = 5, int spd = 10) : HP(hp), skill_count(skill), speed(spd) {
        cout << "Constructor called!" << endl;
        cout << "HP: " << HP << ", Skill Count: " << skill_count << ", Speed: " << speed << endl;
    }
};

int main() {
    Hero hero1(150, 10, 20); // 创建一个 Hero 对象

    return 0;
}