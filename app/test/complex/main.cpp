#include <complex>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define int long long
#define EPS 10e-9

vector<complex<double>> solve(vector<vector<complex<double>>>& x, vector<complex<double>>& y) {
    complex<double> a, b, c;

    for (int i = 0; i < 2; ++i) {

        complex<double> val = x[i][i];
        for (int j = i; j < 3; ++j) {
            x[i][j] /= val;
        }
        y[i] /= val;

        for (int j = 2; j > i; --j) {
            complex<double> factor = x[j][i];
            y[j] -= (factor * y[i]);
            for (int k = i; k < 3; ++k) {
                x[j][k] -= (factor * x[i][k]);
            }
        }
    }

    c = y[2] / x[2][2];
    b = (y[1] - x[1][2] * c) / x[1][1];
    a = (y[0] - x[0][1] * b - x[0][2] * c) / x[0][0];

    return {c, b, a};
}

signed main() {
    vector<complex<double>> xy(6);
    for (int i = 0; i < 6; i++) {
        double real, imag;
        cin >> real >> imag;
        xy[i] = complex<double>(real, imag);
    }

    vector<vector<complex<double>>> matrix_x(3, vector<complex<double>>(3));
    vector<complex<double>> matrix_y(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix_x[i][j] = pow(xy[i * 2], j);
        }

        matrix_y[i] = xy[i * 2 + 1];
    }

    vector<complex<double>> result = solve(matrix_x, matrix_y);

    for (auto& c : result) {
        if (fabs(c.real()) < EPS)
            c.real(0);
        if (fabs(c.imag()) < EPS)
            c.imag(0);
        printf("%.6lf %.6lf\n", c.real(), c.imag());
    }

    return 0;
}
