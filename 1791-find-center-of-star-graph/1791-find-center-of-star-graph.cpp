class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>arr(n+2, 0);
        for(int i = 0; n>i; i++){
            if(++arr[edges[i][0]] == n)return edges[i][0];
            if(++arr[edges[i][1]] == n)return edges[i][1];
        }
        return 0;
    }
};