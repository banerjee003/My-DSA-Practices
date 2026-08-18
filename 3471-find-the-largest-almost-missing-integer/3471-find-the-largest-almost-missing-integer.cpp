class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 1){
            unordered_map<int,int>m;

            for(int num : nums){
                m[num]++;
            }

            int maxVal = INT_MIN;

            for(auto i : m){
                if(i.second == 1){
                    maxVal = max(maxVal, i.first);
                }
            }
            
            if(maxVal != INT_MIN){
                return maxVal;
            }
        }

        else if(k == n){
            int maxVal = INT_MIN;

            for(int i = 0; i < n; i++){
                maxVal = max(maxVal, nums[i]);
            }
            return maxVal;
        }

        else{
            unordered_map<int,int>m;

            for(int i = 0; i < n; i++){
                if(nums[i] == nums[0]){
                    m[0]++;
                }
                if(nums[i] == nums[n-1]){
                    m[n-1]++;
                }
            }

            if(m[0] == 1 && m[n-1] == 1){
                return max(nums[0], nums[n-1]);
            }

            if(m[0] == 1){
                return nums[0];
            }

            if(m[n-1] == 1){
                return nums[n-1];
            }
        }

        return -1;
    }
};
