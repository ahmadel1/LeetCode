//This solution was created using graph theory.
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>>nodes;
        int startNode; 
        int n = adjacentPairs.size();
        vector<int>res;
        for(auto i  : adjacentPairs){
            int parent = i[0], child = i[1];
            if (nodes.count(parent) == 0)
                nodes[parent] = vector<int>();
            nodes[parent].push_back(child);
            nodes[child].push_back(parent);
        }
        
        for(auto i : nodes){
            if(i.second.size() == 1){
                startNode = i.first;
                res.push_back(startNode);
                res.push_back(nodes[startNode][0]);
                break;
            }
        }
        
        for(int i = 0; i<n-1; i++){
            int lastNode = res.back();
            if(res[i] != nodes[lastNode][0])
                res.push_back(nodes[lastNode][0]);
            else
                res.push_back(nodes[lastNode][1]);
        }
        return res;
    }
};