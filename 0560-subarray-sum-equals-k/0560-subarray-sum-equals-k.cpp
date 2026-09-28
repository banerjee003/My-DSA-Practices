class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>m;
        int prefix = 0;

        int count = 0;
        m[0] = 1;
        for(int i = 0; i < n; i++){
            prefix += nums[i];

            int target = prefix - k;
            if(m.find(target) != m.end()){
                count += m[target];
            }
            m[prefix]++;
        }

        return count;
    }
};