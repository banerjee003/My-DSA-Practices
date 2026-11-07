class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int mid = 0;
        while(mid < n && nums[mid] < 0){
            mid++;
        }

        vector<int>ans;

        int left = mid-1;
        int right = mid;

        while(left >= 0 && right < n){
            if((nums[left] * nums[left]) < (nums[right] * nums[right])){
                ans.push_back(nums[left]*nums[left]);
                left--;
            }
            else{
                ans.push_back(nums[right]*nums[right]);
                right++;
            }
        }
        
        while(left >= 0){
            ans.push_back(nums[left] * nums[left]);
            left--;
        }

        while(right < n){
            ans.push_back(nums[right] * nums[right]);
            right++;
        }
        

        return ans;
    }
};