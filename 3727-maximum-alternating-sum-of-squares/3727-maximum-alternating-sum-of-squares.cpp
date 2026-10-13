class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) > abs(b);
        });

        int n = nums.size();
        int x;
         
        if(n % 2 == 0){
            x = n/2;
        }
        else{
            x = (n/2)+1;
        }

        long long sum = 0;

        for(int i = 0; i < n; i++){
            if(i < x){
                sum += (nums[i] * nums[i]);
            }
            else{
                sum -= (nums[i] * nums[i]);
            }
        }
        return sum;
    }
};
