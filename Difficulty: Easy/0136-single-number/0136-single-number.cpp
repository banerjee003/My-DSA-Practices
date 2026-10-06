class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>m;

        for(int i : nums){
            m[i]++;
        }

        for(int i : nums){
            if(m[i] == 1){
                return i;
            }
        }
        return -1;
    }
};