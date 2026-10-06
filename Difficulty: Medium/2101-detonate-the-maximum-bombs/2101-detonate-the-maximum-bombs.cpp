class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>&vis, int &count){
        vis[u] = 1;
        count++;

        for(int i : adj[u]){
            if(!vis[i]){
                dfs(i, adj, vis, count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bomb) {
        int n = bomb.size();
        vector<vector<int>>adj(n);

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                long long dx = bomb[i][0] - bomb[j][0];
                long long dy = bomb[i][1] - bomb[j][1];

                long long distance = (dx * dx) + (dy * dy);

                if(distance <= 1LL * bomb[i][2] * bomb[i][2]){
                    adj[i].push_back(j);
                }
                if(distance <= 1LL * bomb[j][2] * bomb[j][2]){
                    adj[j].push_back(i);
                }
            }
        }

        int maxBomb = 0;

        for(int i = 0; i < n; i++){
            vector<int>vis(n,0);
            int count = 0;
            dfs(i, adj, vis, count);
            maxBomb = max(maxBomb, count);
        }

        return maxBomb;
    }
};
