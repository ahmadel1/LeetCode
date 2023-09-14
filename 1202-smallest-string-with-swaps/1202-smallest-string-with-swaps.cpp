class Solution {
public:
    typedef vector<vector<int>> GRAPH;
    void add_undirected_edge(GRAPH &graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    void dfs(GRAPH& graph, vector<int>&visited, int node, vector<int>& connection){
        visited[node] = 1;
        connection.push_back(node);
        for(int i = 0; graph[node].size()>i; i++){
            int cur = graph[node][i];
            if(!visited[cur])
                dfs(graph, visited, cur, connection);
        }
    }
 
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        GRAPH graph(n);
        vector<char>res(n);
        vector<int>visited(n,0);
        for(auto i : pairs)
            add_undirected_edge(graph, i[0], i[1]);
        
        for(int i = 0; i<n; i++){
            vector<int>indexConnection;
            vector<char>charsConnection;
            if(!visited[i]){
                dfs(graph, visited, i, indexConnection);
                for(auto i : indexConnection){
                    charsConnection.push_back(s[i]);
                }
                sort(charsConnection.begin(), charsConnection.end());
                sort(indexConnection.begin(), indexConnection.end());
                for(int k = 0; indexConnection.size()>k; k++)
                    res[indexConnection[k]] = charsConnection[k];
                
            }
        }
        return string(res.begin(), res.end());

    }
};