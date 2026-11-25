#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long mul = 1;
            int g = 0;
            long long l = 1;

            for(int j = i; j < n; j++) {
                if (mul > LLONG_MAX / nums[j]) {
                    break;
                }
                mul *= nums[j];

                g = gcd(g, nums[j]);
                l = lcm(l, (long long)nums[j]);

                if(mul == 1LL * g * l) {
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};