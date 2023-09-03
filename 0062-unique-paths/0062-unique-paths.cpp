class Solution {
public:
    int uniquePaths(int m, int n) {
        return solve(0, 0, m, n);
    }
    int dp[101][101];

    int solve(int currX, int currY,int m, int n){
        if(currX == n-1 && currY == m-1) return 1;
        if(currX >= n || currY >= m) return 0;
        
        if(dp[currX][currY] != 0) return dp[currX][currY];
        int right = solve(currX+1, currY, m, n);
        int up = solve(currX, currY+1, m, n);
        dp[currX][currY] = right + up;
        return dp[currX][currY];

    }
};