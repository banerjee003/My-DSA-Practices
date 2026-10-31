class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int>st;
        vector<int>suffix(n, -1);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temp[st.top()] <= temp[i]){
                st.pop();
            }

            if(!st.empty()){
                suffix[i] = st.top();
            }

            st.push(i);
        } 

        vector<int>ans(n,0);


        for(int i = 0; i < n; i++){
            if(suffix[i] != -1){
                ans[i] = suffix[i] - i;
            }
        }

        return ans;
    }
};