class Solution {
public:
      bool valid(int i, int j, int m, int n){
        if(i<0 || j < 0|| i>=m || j >= n) return false;
        return true;
    }
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    int func(int i, int j, int m, int n, vector<vector<int>>&dp, vector<vector<int>>& obstacleGrid){
        if(i >=m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m-1 && j ==n-1) return 1;
        int c1 = 0;
        int c2 = 0;
        //down
        if(valid(i+1, j, m, n) && obstacleGrid[i+1][j] != 1){
            c1 = func(i+1, j, m, n, dp, obstacleGrid);
        }
        if(valid(i, j+1, m, n)&& obstacleGrid[i][j+1] != 1){
            c2 = func(i, j+1, m, n, dp, obstacleGrid);
        }
        return dp[i][j] = c1+c2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
         vector<vector<int>>dp(m, vector<int>(n,-1));
        return func(0,0,m,n, dp, obstacleGrid);
    }
};


    