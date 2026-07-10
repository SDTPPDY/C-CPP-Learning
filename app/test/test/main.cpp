#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class TeamWorkBigInt {
  private:
    bool neg;
    string val;

    static string trim(string s) {
        size_t pos = s.find_first_not_of('0');
        if (pos == string::npos)
            return "0";
        return s.substr(pos);
    }

    static bool absLess(const string& a, const string& b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
        return false;
    }

    static string addAbs(const string& a, const string& b) {
        int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            res.push_back(char(sum % 10 + '0'));
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    static string subAbs(const string& a, const string& b) {
        int i = (int)a.size() - 1, j = (int)b.size() - 1, borrow = 0;
        string res;
        while (i >= 0) {
            int diff = (a[i] - '0') - borrow;
            if (j >= 0)
                diff -= (b[j] - '0');
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else
                borrow = 0;
            res.push_back(char(diff + '0'));
            --i;
            --j;
        }
        while (res.size() > 1 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }

    static string mulSmall(const string& a, int b) {
        if (b == 0 || a == "0")
            return "0";
        int carry = 0;
        string res;
        for (int i = (int)a.size() - 1; i >= 0; --i) {
            int prod = (a[i] - '0') * b + carry;
            res.push_back(char(prod % 10 + '0'));
            carry = prod / 10;
        }
        while (carry) {
            res.push_back(char(carry % 10 + '0'));
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    static string divSmall(const string& a, int b) {
        string res;
        int rem = 0;
        for (char ch : a) {
            int cur = rem * 10 + (ch - '0');
            res.push_back(char(cur / b + '0'));
            rem = cur % b;
        }
        return trim(res);
    }

    static string divBig(const string& a, const string& b) {
        if (absLess(a, b))
            return "0";
        string res, rem;
        for (char ch : a) {
            rem.push_back(ch);
            rem = trim(rem);
            int q = 0;
            for (int d = 9; d >= 1; --d) {
                string prod = mulSmall(b, d);
                if (!absLess(rem, prod)) {
                    q = d;
                    rem = subAbs(rem, prod);
                    break;
                }
            }
            res.push_back(char(q + '0'));
        }
        return trim(res);
    }

  public:
    TeamWorkBigInt(int v = 0) {
        if (v < 0) {
            neg = true;
            v = -v;
        }
        else
            neg = false;
        val = to_string(v);
        if (val == "0")
            neg = false;
    }

    TeamWorkBigInt(const string& s, bool n = false) {
        val = trim(s);
        neg = (val == "0") ? false : n;
    }

    friend TeamWorkBigInt pow(const TeamWorkBigInt& base, int exp);
    friend ostream& operator<<(ostream& os, const TeamWorkBigInt& big);

    TeamWorkBigInt operator+(const TeamWorkBigInt& other) const {
        if (neg == other.neg) {
            string sum = addAbs(val, other.val);
            return TeamWorkBigInt(sum, neg);
        }
        if (absLess(val, other.val)) {
            string diff = subAbs(other.val, val);
            return TeamWorkBigInt(diff, other.neg);
        }
        else {
            string diff = subAbs(val, other.val);
            return TeamWorkBigInt(diff, neg);
        }
    }

    TeamWorkBigInt operator-(const TeamWorkBigInt& other) const {
        TeamWorkBigInt t = other;
        t.neg = !t.neg;
        return *this + t;
    }

    TeamWorkBigInt operator*(int small) const {
        if (small == 0)
            return TeamWorkBigInt(0);
        bool resNeg = neg ^ (small < 0);
        int absSmall = small < 0 ? -small : small;
        string prod = mulSmall(val, absSmall);
        return TeamWorkBigInt(prod, resNeg);
    }

    TeamWorkBigInt operator/(int small) const {
        bool resNeg = neg ^ (small < 0);
        int absSmall = small < 0 ? -small : small;
        string quot = divSmall(val, absSmall);
        return TeamWorkBigInt(quot, resNeg);
    }

    TeamWorkBigInt operator/(const TeamWorkBigInt& other) const {
        bool resNeg = neg ^ other.neg;
        string quot = divBig(val, other.val);
        return TeamWorkBigInt(quot, resNeg);
    }

    TeamWorkBigInt& operator+=(const TeamWorkBigInt& other) {
        *this = *this + other;
        return *this;
    }
    TeamWorkBigInt& operator-=(const TeamWorkBigInt& other) {
        *this = *this - other;
        return *this;
    }
    TeamWorkBigInt& operator*=(int small) {
        *this = *this * small;
        return *this;
    }
    TeamWorkBigInt& operator/=(int small) {
        *this = *this / small;
        return *this;
    }
    TeamWorkBigInt& operator/=(const TeamWorkBigInt& other) {
        *this = *this / other;
        return *this;
    }
};

TeamWorkBigInt pow(const TeamWorkBigInt& base, int exp) {
    if (base.val == "10" && !base.neg) {
        string s = "1";
        for (int i = 0; i < exp; ++i)
            s.push_back('0');
        return TeamWorkBigInt(s, false);
    }
    return TeamWorkBigInt(1);
}

ostream& operator<<(ostream& os, const TeamWorkBigInt& big) {
    if (big.neg && big.val != "0")
        os << '-';
    os << big.val;
    return os;
}

int main() {
    int i, N;
    TeamWorkBigInt n = 10, b, x1, x2, s, t, pi;
    cin >> N;
    N--;
    b = pow(n, N + 10);
    x1 = b * 4 / 5;
    x2 = b / -239;
    s = x1 + x2;
    for (i = 3; i <= N * 2; i += 2) {
        x1 /= -25;
        x2 /= -57121;
        t = (x1 + x2) / i;
        s += t;
    }
    pi = s * 4;
    cout << (pi / pow(n, 10)) << endl;
    return 0;
}