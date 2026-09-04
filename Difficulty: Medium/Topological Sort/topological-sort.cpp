class Solution {
  public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj, stack<int>&st){
        vis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        st.push(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>vis(V, 0);
        stack<int>st;
        
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }   
        }
        
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
