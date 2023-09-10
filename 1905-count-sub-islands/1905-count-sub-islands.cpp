class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool validate(int x, int y, int rows, int cols, vector<vector<int>>& grid2, vector<vector<int>>& visited){
        return (x >= 0 && x < cols && y >= 0 && y < rows && grid2[y][x] && !visited[y][x]);
    }
    void findIslands(vector<vector<int>>& grid2, vector<vector<int>>& visited, int y, int x, vector<pair<int,int>>& currentIsland){
        visited[y][x] = 1;
        currentIsland.push_back({y, x});
        for(int i = 0; i<4; i++){
            int newx = x + dx[i],  newy = y + dy[i];
            if(validate(newx, newy, grid2.size(), grid2[0].size(), grid2, visited))
                findIslands(grid2, visited, newy, newx, currentIsland);
            
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> visited(grid2.size(), vector<int>(grid2[0].size(), 0));
        vector<vector<pair<int,int>>> foundIslands;
        for(int i = 0; grid2.size()>i; i++){
            for(int k = 0; grid2[0].size()>k; k++){
                vector<pair<int,int>> currentIsland;
                if(grid2[i][k] && !visited[i][k]){
                    findIslands(grid2, visited, i, k, currentIsland);
                    foundIslands.push_back(currentIsland);
                }
            }
        }
        int result = 0;
        for(auto i : foundIslands){
            int flag = 1;
            for(auto k : i)
               if(grid1[k.first][k.second] == 0){
                    flag = 0;
                    break;
            }
            if(flag == 1) result++;
        }
        return result;

    }
};