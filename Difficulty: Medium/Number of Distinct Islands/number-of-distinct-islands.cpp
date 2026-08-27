class Solution {
  public:
    void dfs(int row, int col, vector<vector<char>>& grid, 
    vector<vector<int>>&vis, vector<pair<int,int>>&ans, int row0, int col0){
        int m = grid.size();
        int n = grid[0].size();
        
        vis[row][col] = 1;
        ans.push_back({row - row0, col - col0});
        
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        
        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n
            && grid[nrow][ncol] == 'L' && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis, ans, row0, col0);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        set<vector<pair<int,int>>>st;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vector<pair<int,int>>ans;
                if(grid[i][j] == 'L' && !vis[i][j]){
                    dfs(i, j, grid, vis, ans, i, j);
                    st.insert(ans);
                }
            }
        }
        return st.size();
    }
};
