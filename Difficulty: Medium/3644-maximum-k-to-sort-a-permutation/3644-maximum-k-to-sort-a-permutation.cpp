class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool sorted = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (sorted) {
                    ans = nums[i];
                    sorted = false;
                } else {
                    ans &= nums[i];
                }
            }
        }

        return sorted ? 0 : ans;
    }
};