class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        int sum = 0;

        while(left <= right && right < nums.size()){
            sum += nums[right];

            while(sum >= target){
                ans = min(ans, right-left+1);
                sum -= nums[left]++;
                left++;
            }

            right++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
