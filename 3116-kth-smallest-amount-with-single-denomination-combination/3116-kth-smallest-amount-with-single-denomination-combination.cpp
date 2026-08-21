class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        // How many valid numbers are <= x?
        auto count = [&](long long x) {

            long long ans = 0;
            int n = coins.size();

            // Try every combination of coins
            for (int mask = 1; mask < (1 << n); mask++) {

                long long lcm = 1;
                int bits = 0;

                for (int i = 0; i < n; i++) {

                    if (mask & (1 << i)) {
                        bits++;

                        lcm = lcm / gcd(lcm, (long long)coins[i]) 
                              * coins[i];

                        if (lcm > x)
                            break;
                    }
                }

                if (lcm > x)
                    continue;

                if (bits % 2 == 1)
                    ans += x / lcm;
                else
                    ans -= x / lcm;
            }

            return ans;
        };

        // Binary search
        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};