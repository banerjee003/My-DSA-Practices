class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int>m;

        for(int i : nums){
            m[i]++;
        }

        int temp = k;
        while(m.count(temp)){
            temp += k;
        }

        return temp;
    }
};