class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>&dp, vector<vector<int>>& grid){
        if(i == m && j == n) return 0;
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int c1 = INT_MAX, c2 = INT_MAX;
        if(i < m-1 && j < n-1){
            c1 = grid[i][j] + solve(i+1, j, m, n, dp, grid);
            c2 = grid[i][j] + solve(i, j+1, m, n, dp, grid);
        }
        else if(i == m-1){
            c2 = grid[i][j] + solve(i, j+1, m, n, dp, grid);
        }
        else if(j == n-1){
            c1 = grid[i][j] + solve(i+1, j, m, n, dp, grid);
        }

        return dp[i][j] = min(c1,c2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(0, 0, m, n, dp, grid);
    }
};