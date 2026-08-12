class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size();
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < n; right++){
            m[nums[right]]++;

            if(m[nums[right]] > k){
                while(m[nums[right]] > k){
                    m[nums[left]]--;
                    left++;
                    
                }
                
            }
            maxLength = max(maxLength, (right - left + 1));
        }
        return maxLength;
    }
};
