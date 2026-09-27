class Solution {
public:
    bool dfs(int row, int col, int idx, string word, vector<vector<char>>& board, vector<vector<int>>&vis){
        int m = board.size();
        int n = board[0].size();

        if(board[row][col] != word[idx]){
            return false;
        }

        if(idx == word.size()-1){
            return true;
        }

        vis[row][col] = 1;
 
        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n
            && !vis[nrow][ncol]){
                if(dfs(nrow, ncol, idx+1, word, board, vis)){
                    return true;
                }
            }
        }
        vis[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>vis(m, vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && board[i][j] == word[0]){
                    if(dfs(i, j, 0, word, board, vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};