class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>suffix(n,0);

        for(int i = 0; i < n-1; i++){
            int curr = prices[i];

            int j = i+1;
            while(j < n){
                if(prices[j] <= curr){
                    suffix[i] = prices[j];
                    break;
                }
                else{
                    j++;
                }
            }
        }

        vector<int>ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = (prices[i] - suffix[i]);
        }

        return ans;
    }
};