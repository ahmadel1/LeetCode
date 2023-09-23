class Solution {
public:
    typedef vector<vector<int>>GRAPH;
    bool bfs(GRAPH& graph, vector<int>& arr, int start){
        
        if(arr[start]==0)return true;
        queue<int>q;
        vector<int>visited(graph.size(), 0);
        visited[start] = 1;
        q.push(start);
        while(!q.empty()){
            int cur = q.front();
            q.pop(); 
            for(int neighbour : graph[cur]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    if(arr[neighbour] == 0)
                        return true;
                }                
            }
        }
        return false;

    }

    void add_edge(GRAPH& graph, vector<int>& arr, int cur){
        if(cur + arr[cur] < graph.size())
            graph[cur].push_back(cur+arr[cur]);
        if(cur - arr[cur] >= 0)
            graph[cur].push_back(cur-arr[cur]);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        GRAPH graph(n);
        for(int i = 0; i<n; i++){
            add_edge(graph, arr, i);
        }
        return bfs(graph, arr, start);

    }
};