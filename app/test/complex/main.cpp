#include <complex>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define int long long
#define EPS 10e-9

vector<complex<double>> solve(vector<vector<complex<double>>>& x, vector<complex<double>>& y) {

    for (int i = 0; i < 3; ++i) {
        complex<double> val = x[i][0];

        for (int j = 0; j < 3; ++j) {
            x[i][j] /= pow(val, 2 - i); // x ** 2 // x[i][0]
        }

        y[i] /= val;
    }

    for (int i = 2; i > 0; --i) {
        y[i] -= y[0];
        for (int j = 0; j < 3; ++j) {
            x[i][j] -= x[0][j];
        }
    }

    for (int i = 1; i < 3; ++i) {
        complex<double> val = x[i][1];

        for (int j = 0; j < 3; ++j) {
            x[i][j] /= pow(val, 2 - i); // x ** 2 // x[i][0]
        }

        y[i] /= val;
    }

    // return {a, b, c};
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
            matrix_x[i][j] = pow(xy[(i - 1) * 2], j);
        }

        matrix_y[i] = xy[(i - 1) * 2 + 1];
    }

    vector<complex<double>> result = solve(matrix_x, matrix_y);

    return 0;
}
