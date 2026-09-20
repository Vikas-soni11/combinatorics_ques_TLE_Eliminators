#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const int N = 200005;

ll fact[N], invFact[N];

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

ll nCr(int n, int r) {
    if (r < 0 || r > n)
        return 0;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    ll ans = 0;

    int l = 0;

    for (int r = 0; r < n; r++) {

        // Make sure:
        // max - min <= k
        while (a[r] - a[l] > k) {
            l++;
        }

        int cnt = r - l + 1;

        // a[r] is fixed as the maximum.
        // Choose remaining m-1 elements
        // from the other cnt-1 elements.
        if (cnt >= m) {
            ans += nCr(cnt - 1, m - 1);
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials
    fact[0] = 1;

    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[N - 1] = modPow(fact[N - 1], MOD - 2);

    for (int i = N - 2; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
