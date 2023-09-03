class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>nodes(n);
        vector<int>visited(n, 0);
        for(int i = 0; edges.size()>i; i++){
            nodes[edges[i][0]].push_back(edges[i][1]);
            visited[edges[i][1]] = 1;
        }
        vector<int>res;
        for(int i = 0; n>i; i++){
            if(visited[i] == 0)res.push_back(i);
        }
        return res;
    }
};