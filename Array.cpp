#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

ll fact[N], invFact[N];

ll modPow(ll a, ll b, ll mod) {
    ll res = 1;

    while (b) {
        if (b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

ll modInv(ll a, ll mod) {
    return modPow(a, mod - 2, mod);
}

void precompute_factorials(int maxN) {
    fact[0] = invFact[0] = 1;

    for (int i = 1; i <= maxN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[maxN] = modInv(fact[maxN], MOD);

    for (int i = maxN - 1; i >= 1; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n)
        return 0;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    ll n;
    cin >> n;

    // Either increasing or decreasing
    // = increasing + decreasing - both

    ll inc = nCr(2 * n - 1, n);
    ll dec = nCr(2 * n - 1, n);

    // Sequences that are both increasing and decreasing
    ll both = n;

    ll ans = (inc + dec - both + MOD) % MOD;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_factorials(N - 1);

    solve();

    return 0;
}
