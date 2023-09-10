class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    bool valid(int r, int c, int rows, int cols, int currColor, vector<vector<int>>& visited, vector<vector<int>>& grid){
        return (r < rows && r >= 0 && c < cols && c >= 0 && !visited[r][c] && grid[r][c] == currColor);
    }    
    void solve(vector<vector<int>>& grid, int row, int col, int currColor, vector<pair<int, int>>& component,  vector<vector<int>>& visited){
        visited[row][col] = 1;
        component.push_back({row, col});
        for(int i  = 0; i < 4; i++){
            int newr = row + dr[i], newc = col + dc[i];
            if(valid(newr, newc, grid.size(), grid[0].size(), currColor, visited, grid))
                solve(grid, newr, newc, currColor, component, visited);
        }
    }
    bool checkBorder(int r, int c, int rows, int cols, vector<vector<int>>& grid, int currColor){
        return !(r < rows && r >= 0 && c < cols && c >= 0 && grid[r][c] == currColor);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>>modifiedGrid(grid.begin(), grid.end());
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<pair<int, int>> component;
        solve(grid, row, col, grid[row][col], component, visited);
        for(int i = 0; component.size()>i; i++){
            for(int  k = 0; 4>k; k++){
                int newr = component[i].first + dr[k], newc =  component[i].second + dc[k];
                if(checkBorder(newr, newc, grid.size(), grid[0].size(), grid, grid[row][col])){
                    modifiedGrid[component[i].first][component[i].second] = color;
                    break;
                }
            }
        }
        return modifiedGrid;
    }
};