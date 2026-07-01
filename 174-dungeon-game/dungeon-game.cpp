class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
       vector<vector<int>>dp(m, vector<int>(n,-1));
        dp[m-1][n-1] = points[m-1][n-1];
        if(points[m-1][n-1] > 0 ) dp[m-1][n-1] = 0;
        for(int i = m-2; i >= 0; i--){
           int sum = points[i][n-1] + dp[i+1][n-1];
           if(sum > 0) sum = 0;
            dp[i][n-1] = sum;
        }
         for(int j = n-2; j >= 0; j--){
           int sum = points[m-1][j] + dp[m-1][j+1];
           if(sum > 0) sum = 0;
            dp[m-1][j] = sum;
        }
        
        for(int i = m-2; i >=0; i--){
            for(int j = n-2; j >=0; j--){
                int s1 = points[i][j] + dp[i+1][j];
                int s2 = points[i][j] + dp[i][j+1];
                
                if(s1 > 0) s1 = 0;
                if(s2 > 0) s2 = 0;
                
                dp[i][j] = max(s1,s2);
            }
        }
        return abs(dp[0][0]) + 1;
    }
};