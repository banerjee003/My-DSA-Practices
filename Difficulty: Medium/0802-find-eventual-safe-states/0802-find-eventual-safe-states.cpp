class Solution {
public:
    bool checkSafeStates(int node, vector<vector<int>>& graph, vector<int>&vis,
    vector<int>&pathVis, vector<int>&check){
        vis[node] = 1;
        pathVis[node] = 1;

        for(int i : graph[node]){
            if(!vis[i]){
                if(!checkSafeStates(i, graph, vis, pathVis, check)){
                    return false;
                }
            }
            else if(pathVis[i]){
                return false;
            }
        }
        pathVis[node] = 0;
        check[node] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>vis(v,0);
        vector<int>pathVis(v,0);
        vector<int>check(v,0);

        for(int i = 0; i < v; i++){
            if(!vis[i]){
                checkSafeStates(i, graph, vis, pathVis, check);
            }
        }

        vector<int>ans;

        for(int i = 0; i < v; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};