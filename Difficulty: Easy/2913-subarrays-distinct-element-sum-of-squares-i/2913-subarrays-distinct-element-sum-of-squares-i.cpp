class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            unordered_set<int>st;
            st.insert(nums[i]);
            for(int j = i+1; j < n; j++){
                st.insert(nums[j]);
                ans += (st.size() * st.size());
            }
        }

        return ans + n;
    }
};