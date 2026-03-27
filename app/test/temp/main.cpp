#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    bool ans = 1;
    s.insert(1);

    auto it = s.insert(1);
    ans = ans && it.second;

    cout << ans << endl;
    
}