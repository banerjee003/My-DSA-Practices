class Solution {
public:
    bool check(int start, int v, vector<int>&color, int col, vector<vector<int>>& graph){
        color[start] = !col;

        for(int i : graph[start]){
            if(color[i] == -1){
                if(!check(i, v, color, !col, graph)){
                    return false;
                }
            }
            else if(color[i] == !col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v, -1);

        for(int i = 0; i < v; i++){
            if(color[i] == -1){
                if(!check(i, v, color, 0, graph))
                    return false;
                
            }
        }
        return true;
    }
};
