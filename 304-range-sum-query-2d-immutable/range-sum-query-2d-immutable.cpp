class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        dp.assign(m+1, vector<int>(n+1, 0));   //dp m+1, n+1 size ki hai mtlb dp[3][4] ka mtlb (0,0) se mat[2][3] ka sum kitna hai

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int curr = matrix[i-1][j-1], top = dp[i-1][j], left = dp[i][j-1], topleft = dp[i-1][j-1];
                dp[i][j] = curr + top + left -(topleft);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int curr = dp[row2+1][col2+1], top = dp[row1][col2+1], left = dp[row2+1][col1], topleft = dp[row1][col1];
        return curr-top-left+topleft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */