class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        dp.assign(m, vector<int>(n, 0));

        for(int i = 0; i < matrix.size(); i++){
            int sum = 0;
            for(int j = 0; j < matrix[i].size(); j++){
                sum+= matrix[i][j];
                dp[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for(int i = row1; i <= row2; i++){
            if(col1 > 0){
                s+=(dp[i][col2] - dp[i][col1-1]);
            }
            else{
                s+= dp[i][col2];
            }
        }
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */