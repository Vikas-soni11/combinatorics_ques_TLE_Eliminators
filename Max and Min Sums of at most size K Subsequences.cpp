class Solution {
public:
    using ll = long long;

    static const int MOD = 1e9 + 7;

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

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> fact(n + 1), invFact(n + 1);
        fact[0] = 1;

        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;


        auto nCr = [&](int n, int r) -> ll {

            if (r < 0 || r > n)
                return 0;

            return fact[n] * invFact[r] % MOD
                         * invFact[n - r] % MOD;
        };

        
        sort(nums.begin(), nums.end());

        ll ans = 0;
        ll S = 1; // sum of i choose 0 + i choose 1 + ... + i choose k-1

        for (int i = 0; i < n; i++) {
            // nums[i] is maximum
            ans += nums[i] * S % MOD;
            ans %= MOD;

            ll remove = nCr(i, k - 1);
            S = (2 * S % MOD - remove + MOD) % MOD;
        }

        reverse(nums.begin() , nums.end());
        S = 1;
        for (int i = 0; i < n; i++) {
            // nums[i] is maximum
            ans += nums[i] * S % MOD;
            ans %= MOD;

            ll remove = nCr(i, k - 1);
            S = (2 * S % MOD - remove + MOD) % MOD;
        }

        return ans;
    }
};
