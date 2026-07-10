#include <iostream>
using namespace std;

class c {
    int a;
};

struct s {
    int a;
};

/*
在class中，成员默认是private的
而在struct中，成员默认是public的
这意味着在class中，成员变量和成员函数只能在类的内部访问
而在struct中，成员变量和成员函数可以在结构体的外部访问
*/

int main() {
    c c1;
    s s1;

    // c1.a = 10; // Error: 'a' is private in class 'c'
    s1.a = 20; // OK: 'a' is public in struct 's'

    return 0;
}