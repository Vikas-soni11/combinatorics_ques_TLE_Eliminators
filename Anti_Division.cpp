#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countMul(ll l, ll r, ll x) {
    return r / x - (l - 1) / x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll multiplesOfC = countMul(A,B,C);
    ll multiplesOfD = countMul(A,B,D);

    ll gcdCD = gcd(C, D);
    ll lcmCD = (C / gcdCD) * D;

    ll multiplesOfBoth = countMul(A,B,lcmCD);

    ll total = B - A + 1;

    //ans = tot - (a + b - a&b)
    ll ans = total - multiplesOfC - multiplesOfD + multiplesOfBoth;
    
    cout<<ans<<endl;

    return 0;
}
