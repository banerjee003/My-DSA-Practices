class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool isswaped = false;
        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int j = n-1;
                while(j >= i){
                    if(nums[j] > nums[i-1]){
                        break;
                    }
                    j--;
                }

                swap(nums[i-1], nums[j]);

                reverse(nums.begin() + i, nums.end());
                isswaped = true;
                break;
            }
        }

        if(!isswaped){
            sort(nums.begin(), nums.end());
        }
    }
};
