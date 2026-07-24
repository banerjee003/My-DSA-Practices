class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int>a, vector<int>b){
            return a[1] < b[1];
        });

        int count = 1;
        int currEnd = pairs[0][1];

        for(int i = 1; i < n; i++){
            if(pairs[i][0] > currEnd){
                currEnd = pairs[i][1];
                count++;
            }
        }
        return count;
    }
};
