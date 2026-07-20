class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>a, const vector<int>b){
            return a[1] < b[1];
        });

        int n = intervals.size();

        int count = 1;
        int currEnd = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= currEnd){
                count++;
                currEnd = intervals[i][1];
            }
        } 
        return n - count;
    }
};
