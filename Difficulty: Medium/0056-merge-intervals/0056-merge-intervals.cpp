class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0] < b[0];
        });

        vector<vector<int>>ans;

        int currst = intervals[0][0];
        int currend = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= currend){
                currend = max(currend, intervals[i][1]);
            }
            else{
                ans.push_back({currst, currend});

                currst = intervals[i][0];
                currend = intervals[i][1];

            }
        }
        ans.push_back({currst, currend});

        return ans;
    }
};