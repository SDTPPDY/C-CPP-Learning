#include <iostream>
using namespace std;

class Hero {
  private:
    int HP;          // 可读写
    int skill_count; // 可读
    int speed;       // 只写

  public:
    Hero(int hp = 100, int skill = 5, int spd = 10) : HP(hp), skill_count(skill), speed(spd) {}

    int getHP() const {
        return HP;
    }

    void setHP(int hp) {
        HP = hp;
    }

    int getSkillCount() const {
        return skill_count;
    }

    void setSpeed(int spd) {
        speed = spd;
    }
};

int main() {
    Hero hero;

    // 可读写
    cout << "HP: " << hero.getHP() << endl; // 读取HP
    hero.setHP(80); // 修改HP
    cout << "Updated HP: " << hero.getHP() << endl; // 读取更新后的HP

    // 可读
    cout << "Skill Count: " << hero.getSkillCount() << endl; // 读取技能数量

    // 只写
    hero.setSpeed(15); // 修改速度

    return 0;
}