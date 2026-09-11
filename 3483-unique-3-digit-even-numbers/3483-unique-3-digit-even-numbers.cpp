class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int>numbers;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;

            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) continue;
                    if(nums[k] % 2 != 0) continue;

                    int x = 100*nums[i] + 10*nums[j] + nums[k];
                    numbers.insert(x);
                }
            }
        }
        return numbers.size();
    }
};
