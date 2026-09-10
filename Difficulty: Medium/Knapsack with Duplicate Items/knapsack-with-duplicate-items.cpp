class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n+1, vector<int>(capacity+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= capacity; j++){
                int currVal = val[i-1];
                int currWt = wt[i-1];
                
                if(currWt <= j){
                    dp[i][j] = max((currVal + dp[i][j-currWt]), dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][capacity];
    }
};
