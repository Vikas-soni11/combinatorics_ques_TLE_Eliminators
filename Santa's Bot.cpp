#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll modPow(ll a, ll b) {
    ll res = 1;

    while (b) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

ll modInv(ll a) {
    return modPow(a, MOD - 2);
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;

        arr[i].resize(size);

        for (int j = 0; j < size; j++)
            cin >> arr[i][j];
    }

    // Count how many people want each item.
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        for (int x : arr[i])
            mp[x]++;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int x : arr[i]) {

            // Probability of choosing this item from this person's list.
            ll probability = modInv(arr[i].size()) * modInv(n) % MOD;

            // Multiply by the fraction of people who want this item.
            probability *= mp[x] * modInv(n) % MOD;
            probability %= MOD;

            ans = (ans + probability) % MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

