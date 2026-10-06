class Solution {
public:
    bool isValid(vector<int>& nums, int n, int k, int maxAllocate){
        int m = 1, allocate = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > maxAllocate){
                return false;
            }

            if(allocate + nums[i] <= maxAllocate){
                allocate += nums[i];
            }
            else{
                m++;
                allocate = nums[i];
            }
        } 
        if(m > k){
            return false;
        }   
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n){
            return -1;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int st = 0;
        int end = sum;
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st)/2;
            if(isValid(nums, n, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        return ans;
    }
};