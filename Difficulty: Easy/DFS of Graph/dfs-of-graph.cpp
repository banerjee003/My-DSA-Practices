class Solution {
  public:
    void dfsHelper(int curr, vector<vector<int>>& adj, vector<bool>&vis, vector<int>&ans){
        vis[curr] = true;
        ans.push_back(curr);
        
        for(int i : adj[curr]){
            if(!vis[i]){
                dfsHelper(i, adj, vis, ans);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool>vis(n,false);
        vector<int>ans;
        
        dfsHelper(0, adj, vis, ans);
        
        return ans;
    }
};