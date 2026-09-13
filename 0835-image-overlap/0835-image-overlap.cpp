class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>>c1;
        vector<pair<int,int>>c2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1){
                    c1.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    c2.push_back({i,j});
                }
            }
        }

        map<pair<int,int>, int>m;
        int ans = 0;

        for(int i = 0; i < c1.size(); i++){
            for(int j = 0; j < c2.size(); j++){
                int dr = (c2[j].first - c1[i].first);
                int dc = (c2[j].second - c1[i].second);

                m[{dr,dc}]++;

                ans = max(ans, m[{dr,dc}]);
            }
        }
        return ans;
    }
};
