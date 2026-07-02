class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i = 0 ; i < m; i++){
            dp[i][n] = m-i;
        }
        for(int j = 0 ; j < n; j++){
            dp[m][j] = n-j;
        }
        for(int i = m-1; i >=0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    // replace
                    int c1 = 1 + dp[i+1][j+1];
                    //insert
                    int c2 = 1 + dp[i][j+1];
                    //delete
                    int c3 = 1 + dp[i+1][j];
                    dp[i][j] = min(c1,min(c2,c3));
                }
            }
        }
        return dp[0][0];
    }
};