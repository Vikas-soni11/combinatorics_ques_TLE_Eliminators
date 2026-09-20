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
    int n , k;
    cin >> n >> k;
    
    ll red = n - k;
    ll blue = k;
    
    for(ll i = 1 ; i <= k ; i++){
        
        ll ans = 0;
        
        // put blue balls in i boxes
        ll putblue = nCr_mod(blue - 1 , i - 1 , MOD);
        
        // fix i boxes , we need i - 1 boxes in between , take and fix them
        // other red balls have i + 1 positions , again stars and bars
        
        if(red < i-1){cout<<0<<endl; continue;}
        
        ll tot = red - (i-1);
        ll bars = i+1;
        
        ll ways = nCr_mod(tot + bars - 1 , bars - 1 , MOD);
        
        ans = putblue * ways;
        ans %= MOD;
        
        cout<<ans<<endl;
    }
}

int main() {
    int t = 1;
    
    precompute_factorials(N-1 , MOD);

    while (t--) solve();
    return 0;
}
