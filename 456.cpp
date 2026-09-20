#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> d1(6), d2(6), d3(6);

    for (int i = 0; i < 6; i++) cin >> d1[i];
    for (int i = 0; i < 6; i++) cin >> d2[i];
    for (int i = 0; i < 6; i++) cin >> d3[i];

    map<int, int> m1, m2, m3;

    for (int i = 0; i < 6; i++) m1[d1[i]]++;
    for (int i = 0; i < 6; i++) m2[d2[i]]++;
    for (int i = 0; i < 6; i++) m3[d3[i]]++;

    double ans = 0;

    // Consider all 6 permutations of 4, 5, 6.
    ans += m1[4] * m2[5] * m3[6]; 
    ans += m1[4] * m2[6] * m3[5]; // pattern (4,6,5) -> (number of 4 in d1 / 6) * (number of 6 in d2 / 6) * (number of 5 in d3 / 6)  [Note : we do divide by 6*6*6 after calculating for all pattens) 
    ans += m1[5] * m2[4] * m3[6];
    ans += m1[5] * m2[6] * m3[4];
    ans += m1[6] * m2[4] * m3[5];
    ans += m1[6] * m2[5] * m3[4];

    ans /= (6 * 6 * 6);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
  
    return 0;
}
