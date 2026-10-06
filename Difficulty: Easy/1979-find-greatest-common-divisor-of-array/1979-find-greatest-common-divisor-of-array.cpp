class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNum = nums[0];
        int maxNum = nums[0];
        for(int i : nums){
            minNum = min(minNum, i);
            maxNum = max(maxNum, i);
        }
        return gcd(minNum, maxNum);
    }
};
