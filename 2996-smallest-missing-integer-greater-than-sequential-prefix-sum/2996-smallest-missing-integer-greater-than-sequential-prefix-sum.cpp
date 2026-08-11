class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        unordered_map<int,int>m;
        bool seq = true;
        m[nums[0]]++;

        for(int i = 1; i < n; i++){
            if(nums[i] != (nums[i-1] + 1)){
                seq = false;
            }

            if(seq){
                sum += nums[i];
            }

            m[nums[i]]++;
        }

        while(true){
            if(!m.count(sum)){
                return sum;
            }
            else{
                sum++;
            }
        }
        return sum;
    }
};
