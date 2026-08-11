class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>m;

        for(int i : nums){
            m[i]++;
        }

        int i = 1;

        while(m.count(i)){
            i++;
        }

        return i;
    }
};