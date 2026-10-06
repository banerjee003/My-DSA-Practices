class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int & b){
            return a > b;
        });

        int n = nums.size();

        int a = nums[0] * nums[1] * nums[2];
        int b = nums[0] * nums[n-1] * nums[n-2];

        return max(a,b);
    }
};
