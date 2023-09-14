class Solution {
public:
    typedef unordered_map<int, vector<int>> GRAPH;
    void add_undirected_edge(GRAPH& graph, int from , int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int dfs(GRAPH& graph, unordered_set<int>& visited, int node){
        visited.insert(node);
        for(auto i : graph[node]){
            if(!visited.count(i))
                return 1 + dfs(graph, visited, i);
        }
        return 1;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        GRAPH graph;
        unordered_set<int> nums_set(nums.begin(), nums.end());
        for(auto i : nums_set){
            if(nums_set.count(i+1))
                add_undirected_edge(graph, i, i+1);
        }
        int res = 1;
        unordered_set<int> visited;
        for (auto &node_adj : graph) {
			if (!visited.count(node_adj.first) && node_adj.second.size() == 1) {
				int tmp = dfs(graph, visited, node_adj.first);
				res = max(res, tmp);
			}
		}
		return res;
        

        
    }
};