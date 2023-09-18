//graph coloring
class Solution {
public:
    bool result  = true;
    void dfs(vector<vector<int>>& groups, vector<int>& colors, int node, int currentColor=1){
        if(colors[node] == 0)
            colors[node] = currentColor;
        else{
            if(colors[node] != currentColor)
                result = false;
            return;
            
        }

        for(auto i : groups[node])
            dfs(groups, colors, i, 3-currentColor);
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n, 0);
        for(int i = 0; n>i; i++){
            if(colors[i] == 0){
                dfs(graph, colors, i);
                if (!result)
                    return false;
            }
        }
        return true;
    }
};