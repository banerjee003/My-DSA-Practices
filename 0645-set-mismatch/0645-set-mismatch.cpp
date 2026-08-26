class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;

        for(int i : nums){
            m[i]++;
        }

        int first=-1, second=-1;
        for(int i = 1; i <= n; i++){
            if(m[i] == 2){
                first = i;
            }
            if(m[i] == 0){
                second = i;
            }
        }

        return {first, second};
    }
};
