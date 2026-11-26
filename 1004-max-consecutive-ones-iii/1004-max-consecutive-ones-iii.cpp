class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right;
        int freq_one = 0;
        int ans = 0;
        int maxlen = 0;

        for(right = 0; right < nums.size(); right++){
            if(nums[right] == 1) {
                freq_one++;
            }

            else{
                while(((right-left+1) - freq_one) > k){
                    if(nums[left] == 1) freq_one--;
                    left++;
                }
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};
