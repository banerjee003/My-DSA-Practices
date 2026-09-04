class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indegree(V,0);
        vector<vector<int>>adj(V);
        
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        
        queue<int>q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(int i : adj[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        return ans;
    }
};
