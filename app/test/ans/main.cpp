#include <iostream>
using namespace std;

/*
在C/C++中，内置的基本数据类型（如 long long）能表示的整数范围有限。当数字长度超过 64 位时，我们就不能直接使用算术类型来存储了。

现在，给你两个超长的非负整数，请你判断它们是否相等。

要求：

定义一个 BigInteger 类，在内部存储数字。
比较A和B是否相等时，禁止使用 long long、__int128、double 等类型直接存储完整的输入数字。

输入保证：给出的数字含前导零。

输入格式

输入包含两行，每行一个非负整数。

长度不超过 100,000 个字符。

输出格式

如果两个整数相等，输出 YES，否则输出 NO。
*/

/*
样例 1

text
000123
123
样例 1 输出

text
YES

样例 2

text
0123
1230
样例 2 输出

text
NO

样例 3

text
0
000
样例 3 输出

text
YES

样例 4

text
00000000000000000000000000000000000000000000000001
1
样例 4 输出

text
YES
*/

class BigInteger {
  private:
    string value;

    string normalize() const {
        int pos = 0;
        int len = value.size();
        while (pos < len && value[pos] == '0') {
            pos++;
        }

        if (pos == len) {
            return "0";
        }

        string result;
        for (int i = pos; i < len; i++) {
            result.push_back(value[i]);
        }
        return result;
    }

  public:
    BigInteger() {}

    bool operator==(const BigInteger& other) const {
        return this->normalize() == other.normalize();
    }

    friend istream& operator>>(istream& in, BigInteger& num) {
        in >> num.value;
        return in;
    }
};

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/*
世界杯·球迷出行时间计算

题目背景

2026 年世界杯激战正酣！小明要从家前往球场观看比赛。他有三种交通工具可以选择：

汽车：在城市道路上行驶，速度受交通状况影响。
火车：在铁轨上行驶，速度较快，但可能需要中转等待。
飞机：在空中飞行，速度最快，但机场距离市区较远，需要额外的地面交通时间。
小明想知道，选择哪一种交通工具能最快到达球场。

题目描述

请设计一个面向对象的程序，计算并输出最快到达时间。

你需要定义以下类：

Vehicle（交通工具类）

是一个抽象基类。
包含一个纯虚函数 double travelTime()，用于计算该交通工具从家到球场所需的总时间（小时）。
可以包含共有的属性（如距离、速度等）。
Car（汽车类）

继承自 Vehicle。
属性：距离（公里）、基础速度（公里/小时）、拥堵系数（0~1之间的浮点数，表示路况，越小越拥堵）。
计算时间公式：距离 / (基础速度 × 拥堵系数)。
Train（火车类）

继承自 Vehicle。
属性：距离（公里）、速度（公里/小时）、中转等待时间（小时）。
计算时间公式：距离 / 速度 + 中转等待时间。
Plane（飞机类）

继承自 Vehicle。
属性：飞行距离（公里）、飞行速度（公里/小时）、机场往返地面交通时间（小时）。
计算时间公式：飞行距离 / 飞行速度 + 地面交通时间。
输入格式

输入包含三行，分别对应三种交通工具的参数：

第一行：三个浮点数 carDist carSpeed congestion
分别表示汽车行驶距离、基础速度、拥堵系数（0 < congestion ≤ 1）。
第二行：三个浮点数 trainDist trainSpeed waitTime
分别表示火车行驶距离、速度、中转等待时间（≥ 0）。
第三行：三个浮点数 planeDist planeSpeed groundTime
分别表示飞机飞行距离、飞行速度、地面交通时间（≥ 0）。
输出格式

输出一个浮点数，保留两位小数，表示三种交通工具中最短的时间。
*/