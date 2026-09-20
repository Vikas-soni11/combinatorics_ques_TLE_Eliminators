#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1e9 + 7;
const ll N = 1e5 + 1000;

ll modPow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll modInv(ll a, ll m) {
    return modPow(a, m - 2, m);
}

ll fact[N], invFact[N];


void precompute_factorials(int maxN, int m = MOD) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= maxN; i++)
        fact[i] = fact[i - 1] * i % m;
    invFact[maxN] = modInv(fact[maxN], m);
    for (int i = maxN - 1; i >= 1; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % m;
}

ll nCr_mod(int n, int r, int m = MOD) {
    if (r > n || n < 0 || r < 0) return 0;
    return fact[n] * invFact[r] % m * invFact[n - r] % m;
}



ll mod_mult(ll a, ll b, ll m) {
    return (a % m * b % m) % m;
}

void solve() {
    int k;
    cin >> k;

    vector<int> balls(k); 
    for(int i = 0 ; i < k ; i++) cin>>balls[i];

    ll ans = 1;
    ll total = 0;

    for(int i = 0 ; i < k ; i++){
        // fix one ball at the end other arr[i] - 1 balls have total + 1 position

        // like distributing balls[i] - 1 chocolates to total + 1 children
        ans *= nCr_mod((balls[i] - 1) + (total + 1) - 1 , balls[i] - 1  , MOD);
        ans %= MOD;

        total += balls[i];
    }

    cout<<ans;
}

int main() {
    int t = 1;
    
    precompute_factorials(N-1 , MOD);

    while (t--) solve();
    return 0;
}
