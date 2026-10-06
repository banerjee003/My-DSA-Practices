class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,0);

        for(int i = 1; i < n+1; i++){
            int oneday = dp[i-1] + costs[0];

            int j = i-1;
            while(j >= 0 && days[j] >= days[i-1] - 6){
                j--;
            }
            int sevenday = dp[j + 1] + costs[1];

            int k = i-1;
            while(k >= 0 && days[k] >= days[i-1] - 29){
                k--;
            }
            int thirtyday = dp[k+1] + costs[2];

            dp[i] = min(oneday, min(sevenday, thirtyday));
        }

        return dp[n];
    }
};
