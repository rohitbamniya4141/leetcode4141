class Solution {
public:
   
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1, false);
        dp[0] = false;
        for(int i = 1; i <= n; i++){
            for(int t =1; t*t <=i; t++){
                int square = t*t;

                if(!dp[i-square]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};