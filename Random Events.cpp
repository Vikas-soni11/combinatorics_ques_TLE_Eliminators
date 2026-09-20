#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;

using ll = long long;

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll need = -1;

    // Find the last position where the array differs from [1, 2, ..., n].
    for (ll i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            need = i + 1;
    }

    vector<pair<ll, double>> queries(q);

    for (ll i = 0; i < q; i++) {
        ll a;
        double b;

        cin >> a >> b;
        queries[i] = {a, b};
    }

    double ans = 1.0;

    // Already sorted.
    if (need == -1) {
        cout << fixed << setprecision(8) << ans << '\n';
        return;
    }

    double failure = 1.0;

    for (ll i = 0; i < q; i++) {
        if (queries[i].first >= need)
            failure *= (1.0 - queries[i].second);
    }

    ans = 1.0 - failure;

    cout << fixed << setprecision(8) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}
