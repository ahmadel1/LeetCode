class Solution {
public:
    void solve(vector<vector<int>>& rooms, int current, vector<int>& visited){
        if(visited[current] == 1)return;
        visited[current] = 1;
        if(rooms[current].size() == 0)return;
        for(int i = 0; rooms[current].size()>i; i++){
            solve(rooms, rooms[current][i], visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, 0);
        solve(rooms, 0, visited);
        int res = 0;
        for(auto i : visited)
            if(i==1)res++;
            
        return res == n ? true : false;
    }
};