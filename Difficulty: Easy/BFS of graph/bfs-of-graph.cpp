class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<bool>vis(n, false);
        queue<int>q;
        q.push(0);
        vis[0] = true;
        
        vector<int>ans;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            for(int i : adj[curr]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
};
