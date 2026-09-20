```cpp
#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int blue = 0;
    int red = 0;

    for (int i = 0; i < n; i++) {
        if (s1[i] < s2[i])
            blue++;
        else if (s1[i] > s2[i])
            red++;
    }

    if (blue > red)
        cout << "BLUE\n";
    else if (blue < red)
        cout << "RED\n";
    else
        cout << "EQUAL\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
```
