class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int valid(int r, int c, vector<vector<char>>& grid){
        return (r>=0 && r<grid.size() && c>=0 && c<grid[0].size());
    }
    bool is_cycle;
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited, char oldColor, int par_r, int par_c){
        if(!valid(r, c, grid) || grid[r][c] != oldColor || is_cycle)
            return;
        if(visited[r][c]){
            is_cycle = true;
            return;
        }
        visited[r][c] = 1;
        for(int i = 0; i<4; i++){
            int newr = r + dr[i], newc = c + dc[i];
            if(newr == par_r && newc == par_c)
                continue;
            dfs(newr, newc, grid, visited, oldColor, r, c);
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
		int rows = grid.size(), cols = grid[0].size();

		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				if (!visited[r][c]) {	
					is_cycle = false;
					dfs(r, c, grid, visited, grid[r][c], -1, -1);
					if (is_cycle)
						return true;
				}
			}
		}
		return false;
    }
};
