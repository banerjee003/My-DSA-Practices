class Solution {
public:
    int bfs(int start, int v, vector<vector<int>>& adj, vector<int>&vis){
        queue<int>q;
        int level = 1;

        q.push(start);
        q.push(-1);
        vis[start] = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(curr == -1){
                if(!q.empty()){
                    level += 1;
                    q.push(-1);
                }
            }
            else{
                for(auto i : adj[curr]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
        return level;
    }

    bool bipartiteHelper(int start, int col, vector<int>&color, vector<vector<int>>& adj){
        color[start] = !col;

        for(auto i : adj[start]){
            if(color[i] == -1){
                if(!bipartiteHelper(i, !col, color, adj)){
                    return false;
                }
            }
            else if(color[i] == !col){
                return false;
            }
        }
        return true;
    }

    bool bipartite(int start, int v, vector<vector<int>>& adj){
        vector<int>color(v+1, -1);

        for(int i = 1; i <= v; i++){
            if(color[i] == -1){
                if(!bipartiteHelper(i, 0, color, adj)){
                    return false;
                }
            }
        }
        return true;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n+1);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        if(!bipartite(1, n, adj)){
            return -1;
        }

        vector<int>compVis(n+1, 0);
        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(compVis[i]){
                continue;
            }

            vector<int>component;
            queue<int>q;

            q.push(i);
            compVis[i] = 1;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                component.push_back(curr);

                for(int i : adj[curr]){
                    if(!compVis[i]){
                        compVis[i] = 1;
                        q.push(i);
                    }
                }
            }

            int mx = 0;
            
            for(auto node : component){
                vector<int>vis(n+1, 0);
                mx = max(mx, bfs(node, n, adj, vis));
            }
            ans += mx;
        }
        return ans;
    }
};
