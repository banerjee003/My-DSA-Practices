class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        long long sum = 0;
        int ans = INF;
        int minLen = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Carry forward the best subarray
            // found before this position
            if (right > 0)
                best[right] = best[right - 1];

            if (sum == target) {

                int currLen = right - left + 1;

                // If a previous subarray exists completely
                // before 'left', combine them.
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, best[left - 1] + currLen);
                }

                // Current subarray can become the best
                // for future subarrays.
                best[right] = min(best[right], currLen);
            }
        }

        return ans == INF ? -1 : ans;
    }
};