class Solution {
public:
    int counter = 0;
    void dfs(vector<vector<pair<int,int>>>& undirected, vector<int>&visited, int node = 0){
        visited[node] = 1;
        for(auto i : undirected[node]){
            if(!visited[i.first]){
                counter += i.second;
                dfs(undirected, visited, i.first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>>undirected(n);
        for(auto i : connections){
            undirected[i[0]].push_back({i[1], 1});
            undirected[i[1]].push_back({i[0], 0});
        }
        vector<int> visited(n, 0);
        dfs(undirected, visited);
        return counter;
    }
};