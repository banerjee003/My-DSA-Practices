
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int maxDiff = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (k >= total) return 0;

        vector<long long> freq(maxDiff + 1, 0);

        for (int d : diff) {
            freq[d]++;
        }

        for (int d = maxDiff; d > 0 && k > 0; d--) {
            long long moves = min(freq[d], k);

            freq[d] -= moves;
            freq[d - 1] += moves;
            k -= moves;
        }

        long long ans = 0;

        for (int d = 1; d <= maxDiff; d++) {
            ans += freq[d] * d * d;
        }

        return ans;
    }
};
