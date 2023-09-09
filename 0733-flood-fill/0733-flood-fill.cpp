class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool validate(int x, int y, int rows, int cols, vector<vector<int>>& visited) {
        if (y < rows && y >= 0 && x < cols && x >= 0 && !visited[y][x])
            return true;
        return false;
    }
    void solve(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color, int rows, int cols, vector<vector<int>>& visited, int originalColor){
        ans[sr][sc] = color;
        visited[sr][sc] = 1;
        for(int i = 0; 4>i; i++){
            int newX = sc + dx[i];
            int newY = sr + dy[i];
            if(validate(newX, newY, rows, cols, visited) && originalColor == image[newY][newX])
                solve(image, ans, newY, newX, color, rows, cols, visited, originalColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows=image.size(), cols = image[0].size();
        vector<vector<int>>ans(image.begin(), image.end());
        vector<vector<int>>visited(rows, vector<int>(cols, 0));
        solve(image, ans, sr, sc, color, rows, cols, visited, image[sr][sc]);
        return ans;

    }
};