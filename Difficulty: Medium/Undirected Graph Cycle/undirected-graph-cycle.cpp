class Solution {
  public:
    bool dfs(int curr, int par, vector<vector<int>>&adj, vector<int>&vis){
        vis[curr] = 1;
        
        for(int i : adj[curr]){
            if(!vis[i]){
                if(dfs(i, curr, adj, vis)){
                    return true;
                }
            }
            else if(i != par){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<int>vis(V,0);
        
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i , -1, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};