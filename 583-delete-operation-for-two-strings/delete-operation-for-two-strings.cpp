class Solution {
public:
    int minDistance(string s, string s2) {
        int m = s.size();
        int n = s2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >=0; j--){
                if(s[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    int c1 = dp[i+1][j];
                    int c2 = dp[i][j+1];
                    dp[i][j] = max(c1,c2);
                }
            }
        }
        return n+m-2*dp[0][0];
    }
};