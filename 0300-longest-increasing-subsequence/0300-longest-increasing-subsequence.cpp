class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        vector<int>dup;

        for(int i : nums){
            if(s.find(i) == s.end()){
                dup.push_back(i);
            }
            s.insert(i);
        }

        sort(dup.begin(), dup.end());
        int m = dup.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(nums[i-1] == dup[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};