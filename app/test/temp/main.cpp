#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    unordered_set<int> s;
    bool ans = 1;
    s.insert(1);

    auto it = s.insert(1);
    ans = ans && it.second;

    vector<int> v = {1, 2, 3, 4, 5};
    auto i = v.erase(v.begin() + 2);
    v.push_back(6);

    cout << ans << endl;
}