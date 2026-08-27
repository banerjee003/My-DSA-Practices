class Solution {
public:
    bool check(int start, int v, vector<int>&color, vector<vector<int>>& graph){
        queue<int>q;

        q.push(start);
        color[start] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i : graph[curr]){
                if(color[i] == -1){
                    color[i] = !color[curr];
                        q.push(i);
                }
                else if(color[i] == color[curr]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v, -1);

        for(int i = 0; i < v; i++){
            if(color[i] == -1){
                if(!check(i, v, color, graph))
                    return false;
                
            }
        }
        return true;
    }
};