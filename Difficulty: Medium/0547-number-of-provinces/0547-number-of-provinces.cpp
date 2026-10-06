class Solution {
public:
    void bfs(int u, vector<vector<int>>adj, vector<bool>&vis){
        vis[u] = true;
        
        for(int i : adj[u]){
            if(!vis[i]){
                bfs(i, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>>adj(v+1);

        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<bool>vis(v+1, false);
        int count = 0;

        for(int i = 1; i < v+1; i++){
            if(!vis[i]){
                count++;
                bfs(i, adj, vis);
            }
        }

        return count;
    }
};
