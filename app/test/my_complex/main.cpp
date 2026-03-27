#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Cmycomplex {
  private:
    double real;
    double imag;

  public:
    Cmycomplex(double r = 0, double i = 0) : real(r), imag(i) {}

    friend Cmycomplex operator+(const Cmycomplex& other_1, const Cmycomplex& other_2) {
        return Cmycomplex(other_1.real + other_2.real, other_1.imag + other_2.imag);
    }

    Cmycomplex Add(const Cmycomplex& other) {
        real += other.real;
        imag += other.imag;
        return Cmycomplex(real, imag);
    }

    friend Cmycomplex operator-(const Cmycomplex& other_1, const Cmycomplex& other_2) {
        return Cmycomplex(other_1.real - other_2.real, other_1.imag - other_2.imag);
    }

    friend Cmycomplex operator*(const Cmycomplex& other_1, const Cmycomplex& other_2) {
        return Cmycomplex(other_1.real * other_2.real - other_1.imag * other_2.imag,
                          other_1.real * other_2.imag + other_1.imag * other_2.real);
    }

    friend Cmycomplex operator/(const Cmycomplex& other_1, const Cmycomplex& other_2) {
        double den = other_2.real * other_2.real + other_2.imag * other_2.imag;
        return Cmycomplex((other_1.real * other_2.real + other_1.imag * other_2.imag) / den,
                          (other_1.imag * other_2.real - other_1.real * other_2.imag) / den);
    }

    bool operator==(const Cmycomplex& other) {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Cmycomplex& other) {
        return !(*this == other);
    }

    friend istream& operator>>(istream& is, Cmycomplex& c) {
        is >> c.real >> c.imag;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Cmycomplex& c) {
        if (fabs(c.imag) < 1e-9 && fabs(c.real) < 1e-9)
            os << "(0+0i)";
        else if (c.imag >= 0)
            os << "(" << static_cast<double>(c.real) << "+" << static_cast<double>(c.imag) << "i)" << endl;
        else
            os << "(" << static_cast<double>(c.real) << "-" << static_cast<double>(-c.imag) << "i)" << endl;
        return os;
    }

    double GetReal() const {
        return real;
    }
    double GetImaginary() const { return imag; }

    void Set(double r, double i) {
        real = r;
        imag = i;
    }

    void Show() {
        if (fabs(imag) < 1e-9 && fabs(real) < 1e-9)
            printf("(0+0i)\n");
        else if (imag >= 0)
            printf("(%g+%gi)\n", static_cast<double>(real), static_cast<double>(imag));
        else
            printf("(%g-%gi)\n", static_cast<double>(real), static_cast<double>(-imag));
    }

    double gety() const { return imag; }
    double getx() const { return real; }
};

Cmycomplex sqrt(const Cmycomplex& z) {
    double mag = std::sqrt(z.getx() * z.getx() + z.gety() * z.gety());
    double angle = std::atan2(z.gety(), z.getx()) / 2;
    return Cmycomplex(std::sqrt(mag) * std::cos(angle), std::sqrt(mag) * std::sin(angle));
}
