#include <iostream>
using namespace std;

class AddFunction {
  private:
    int ans;

  public:
    int operator()(int a, int b) {
        ans = a + b;
        return a + b;
    }
};

template <typename T>
class Complex;

template <typename T>
Complex<T> operator-(const Complex<T>& a, const Complex<T>& b);

template <typename T>
class Complex {
    friend Complex<T> operator- <T>(const Complex<T>& a, const Complex<T>& b);

  private:
    T real;
    T imag;

  public:
    Complex(T real = 0, T imag = 0) : real(real), imag(imag) {}
    ~Complex() {}

    Complex<T> operator+(const Complex<T>& other) {
        return Complex<T>(real + other.real, imag + other.imag);
    }
    // 前置++
    Complex<T>& operator++() {
        this->real++;
        return *(this);
    }
    // 后置++
    Complex<T> operator++(int) {
        Complex<T> temp = *this;
        this->real += 1;
        return temp;
    }

    void show() const {
        cout << real << ' ' << imag << 'i' << endl;
    }

    friend ostream& operator<<(ostream& os, const Complex<T>& other) {
        os << other.real << ' ' << other.imag << 'i';
        return os;
    }
    friend istream& operator>>(istream& is, Complex<T>& other) {
        is >> other.real >> other.imag;
        return is;
    }
};

template <typename T>
Complex<T> operator-(const Complex<T>& a, const Complex<T>& b) {
    return Complex<T>(a.real - b.real, a.imag - b.imag);
}

int main() {
    Complex<double> a(1, 2);
    Complex<double> b(2, 3);

    Complex<double> c = a + b;
    Complex<double> d = a - b;

    c.show();
    cout << d << endl;

    cin >> c;
    cout << c << endl;

    cout << ++a << endl;
    cout << a++ << endl;
    cout << a << endl;

    cout << "----------" << endl;
    AddFunction add;
    cout << add(1, 2) << endl;
    cout << add(3, 4) << endl;
}