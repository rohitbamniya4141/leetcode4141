class Solution {
public:
    
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));

        for(int i = m-1; i >= 0 ; i--){
            dp[i][n] = false;
        }
        for(int j = n-1; j >= 0 ;j--){
            if(p[j] == '*'){
                dp[m][j] = dp[m][j+1];
            }
            else dp[m][j] = false;
        }
        dp[m][n]= true;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >=0; j--){
                if((s[i] == p[j]) || (p[j] == '?')){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(p[j] == '*'){
                    bool c1 = dp[i+1][j];
                    bool c2 = dp[i][j+1];
                    dp[i][j] = c1||c2;
                }
                else dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};