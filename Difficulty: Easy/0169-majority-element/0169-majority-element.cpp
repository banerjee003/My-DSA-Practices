class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i : nums){
            m[i]++;
            if(m[i] > (n/2)){
                return i;
            }
        }
        return -1;
    }
};