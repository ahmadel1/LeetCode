class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>>result(r, vector<int>(c));
        vector<int>rowsCount(r), colsCount(c);
        for(int i = 0; i < r; i++)
            for(int k = 0; k < c; k++)
                if(grid[i][k]){
                    rowsCount[i]++;
                    colsCount[k]++;
                }
            
        for(int i = 0; i < r; i++)
            for(int k = 0; k < c; k++)
                result[i][k] = 2*rowsCount[i] + 2*colsCount[k] - (r+c);
        return result; 

    }
};