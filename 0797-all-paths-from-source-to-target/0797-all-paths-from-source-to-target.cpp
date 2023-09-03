class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<vector<int>>& graph, int start, int end, vector<int>tmp){
        tmp.push_back(start);
        if(start == end){
            res.push_back(tmp);
            return;
        } 
        if(graph[start].size() == 0)return;

        for(int i = 0; graph[start].size() > i; i++){
            solve(graph, graph[start][i], end, tmp);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
         vector<int>tmp;
        solve(graph, 0, n-1, tmp);
        return res;
    }
};