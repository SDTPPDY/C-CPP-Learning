#include <iostream>

#include <cmath>

using namespace std;

class Point { // Point类定义
  public:     // 外部接口
    Point(int newx = 0, int newy = 0, int times = 0) {
        x = newx;
        y = newy;
        TimesofGetMysize = times;
    }

    int& getX() { return x; }
    int getX() const { return x; }
    int& getY() { return y; }
    int getY() const { return y; }

    int getMysize() {
        TimesofGetMysize++;
        return Mysize;
    }

    int getTimesofGetMysize() { return TimesofGetMysize; }

    friend float dist(const Point& p1, const Point& p2);
    friend float dist(Point& p1, const Point& p2);

  private: // 私有数据成员，数据成员的定义没有错
    int x, y;
    int TimesofGetMysize;
    const int Mysize = sizeof(Point);
};

void TestFun(Point p) {
    cout << "TestFun is " << p.getX();
}

float dist(const Point& p1, Point& p2) {
    double x = p1.getX() - p2.getX();
    double y = p1.getY() - p2.getY();
    p2.getX()++;
    return static_cast<float>(sqrt(x * x + y * y));
}

float dist(Point& p1, const Point& p2) {
    double x = p1.getX() - p2.getX();
    double y = p1.getY() - p2.getY();
    p1.getX()++;
    return static_cast<float>(sqrt(x * x + y * y));
}
