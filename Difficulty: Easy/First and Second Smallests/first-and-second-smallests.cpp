class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        int m = INT_MAX, s = INT_MAX;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < s){
                if(arr[i] < m){
                    s = m; 
                    m = arr[i];
                }
                else if(arr[i] < s and arr[i] > m){
                    s = arr[i];
                }
            }
        }
        if(s == INT_MAX){
            return {-1};
        }
        return {m,s};
    }
};
