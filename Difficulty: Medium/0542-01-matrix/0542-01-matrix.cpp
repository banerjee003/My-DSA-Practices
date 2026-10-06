class Solution {
public:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis, vector<vector<int>>& ans){
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>, int>>q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            ans[row][col] = steps;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for(int i = 0; i < 4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                    q.push({{nrow,ncol}, steps+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<vector<int>>ans(n, vector<int>(m,0));

        bfs(mat, vis, ans);

        return ans;
    }
};
