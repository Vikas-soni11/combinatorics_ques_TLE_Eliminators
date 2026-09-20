class Solution {
public:

    pair<int, int> removeFactor(int x, int p) {
        int cnt = 0;

        while (x % p == 0) {
            x /= p;
            cnt++;
        }

        return {x, cnt};
    }

    int inverse10(int x) {
        for (int i = 1; i < 10; i++) {
            if ((x * i) % 10 == 1)
                return i;
        }

        return 1;
    }

    int triangularSum(vector<int>& nums) {

        int n = nums.size();
        int N = n - 1;

        long long unit = 1;
        int cnt2 = 0;
        int cnt5 = 0;

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // Calculate C(N, i) modulo 10

            int coeff;

            if (cnt2 > 0 && cnt5 > 0) {
                coeff = 0;
            }
            else if (cnt5 > 0) {
                // 5^positive ≡ 5 (mod 10)
                coeff = unit * 5 % 10;
            }
            else if (cnt2 > 0) {
                // 2^k cycles: 2,4,8,6
                int p = 1;
                for (int j = 0; j < cnt2; j++)
                    p = p * 2 % 10;

                coeff = unit * p % 10;
            }
            else {
                coeff = unit;
            }

            ans = (ans + nums[i] * coeff) % 10;

            if (i == n - 1)
                break;

            // C(N, i+1)
            // = C(N,i) * (N-i)/(i+1)

            int numerator = N - i;
            int denominator = i + 1;

            auto [numWithout2, add2] =
                removeFactor(numerator, 2);

            auto [numWithout25, add5] =
                removeFactor(numWithout2, 5);

            auto [denWithout2, sub2] =
                removeFactor(denominator, 2);

            auto [denWithout25, sub5] =
                removeFactor(denWithout2, 5);

            cnt2 += add2 - sub2;
            cnt5 += add5 - sub5;

            // Only factors coprime with 10 remain
            unit = unit * numWithout25 % 10;

            int inv = inverse10(denWithout25);

            unit = unit * inv % 10;
        }

        return ans;
    }
};
