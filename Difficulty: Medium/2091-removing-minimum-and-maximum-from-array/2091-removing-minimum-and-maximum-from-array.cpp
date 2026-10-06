class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;
        int maxIdx = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
            if(nums[i] <= nums[minIdx]){
                minIdx = i;
            }
        }

        int a = min(minIdx, maxIdx);
        int b = max(minIdx, maxIdx);

        int left = b + 1;
        int right = n - a;
        int both = (a + 1) + (n - b);

        return min({left, right, both});
    }
};
