class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0 , 1, -1};

    bool valid(int r, int c, int rows, int cols, vector<vector<int>>& visited, vector<vector<int>>&grid){
        return (r >= 0 && r < rows && c >= 0 && c < cols && !grid[r][c] && !visited[r][c]);
    }
    
    bool checkBorder(int r, int c, int rows, int cols){
        return (r == 0 || r == rows-1 || c == 0 || c == cols-1);
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>&visited, vector<pair<int, int>>& island, int& flag){
        visited[r][c] = 1;
        for(int i = 0; 4>i; i++){
            int newr = r + dr[i], newc = c + dc[i];
            if(valid(newr, newc, grid.size(), grid[0].size(), visited, grid)){
                if(checkBorder(newr, newc, grid.size(), grid[0].size()))
                    flag = 0;
                dfs(newr, newc, grid, visited, island, flag);
            }
        }
    }
   
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<pair<int, int>>>islands;
        int result = 0;
        
        for(int i = 0; grid.size()>i; i++){
            for(int k = 0; grid[0].size()>k; k++){
                vector<pair<int, int>>island;
                if(!checkBorder(i, k, grid.size(), grid[0].size())){
                    if(valid(i, k, grid.size(), grid[0].size(), visited, grid)){
                        int flag = 1;
                        dfs(i, k, grid, visited, island, flag);
                        if(flag)result++;
                    }
                }
            }
        }
        return result;
    }
};