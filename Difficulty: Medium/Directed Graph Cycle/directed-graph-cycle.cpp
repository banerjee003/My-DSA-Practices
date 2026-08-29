class Solution {
  public:
    bool checkDfs(int node, vector<int>&vis, vector<int>&pathVis,
    vector<vector<int>>&adj){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(int i : adj[node]){
            if(!vis[i]){
                if(checkDfs(i, vis, pathVis, adj)){
                    return true;
                }
            }
            else if(pathVis[i]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(checkDfs(i, vis, pathvis, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};