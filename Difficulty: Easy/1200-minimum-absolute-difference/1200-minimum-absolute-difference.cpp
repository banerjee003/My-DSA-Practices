class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>>ans;
        int mindiff = INT_MAX;
        
        for(int i = 0; i < n-1; i++){
            int diff = arr[i+1] - arr[i];
            if(diff == mindiff){
                ans.push_back({arr[i],arr[i+1]});
                continue;
            }
            if(diff < mindiff){
                ans.clear();
                mindiff = diff;
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
