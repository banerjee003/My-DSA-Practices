class Solution {
  public:
    int cutRod(vector<int>&prices) {
        // code here
        int length = prices.size();
        vector<vector<int>>dp(length+1, vector<int>(length+1, 0));

        for(int i = 1; i < length+1; i++){
            for(int j = 1; j < length+1; j++){
                if(i <= j){
                    int ans1 = dp[i][j - i] + prices[i-1];
                    int ans2 = dp[i-1][j];
                    dp[i][j] = max(ans1, ans2);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[length][length];
    }
};
