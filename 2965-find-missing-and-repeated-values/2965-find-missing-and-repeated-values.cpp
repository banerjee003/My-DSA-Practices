class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeated, missing;
        unordered_map<int,int>m;
        int n = grid.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                m[grid[i][j]]++;
            }
        }

        for(int count = 1; count <= n*n; count++){
            if(m.find(count) == m.end()){
                missing = count;
            }
            if(m[count] == 2){
                repeated = count;
            }
        }

        return {repeated,missing};
    }
};
