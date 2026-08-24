class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>&grid, vector<vector<bool>>&vis){
        vis[row][col] = true;
        int n = grid.size();
        int m = grid[0].size();
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        
        int count = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};
