class Solution {
public:
    void minimax(vector<int>&dp, int i, int n, vector<int>& stoneValue){
        if(i < 0) return;
    
        if(n-i >= 3){
            //teen value
            int take = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2];
            int c1 = take - dp[i+3];

            // 2 value
            take = stoneValue[i] + stoneValue[i+1];
            int c2 = take - dp[i+2];

            //1 value
            take = stoneValue[i];
            int c3 = take - dp[i+1];

            dp[i] = max(c1,max(c2,c3));
            minimax(dp, i-1, n, stoneValue);
        }
        else if(n-i == 2){
             // 2 value
            int take = stoneValue[i] + stoneValue[i+1];
            int c1 = take - dp[i+2];

            //1 value
            take = stoneValue[i];
            int c2 = take - dp[i+1];

            dp[i] = max(c1,c2);
            minimax(dp, i-1,n, stoneValue);
        }
        else{
            int take = stoneValue[i];
            int c1 = take - dp[i+1];

            dp[i] = c1;

            minimax(dp, i-1,n, stoneValue);
        }
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n+1, 0);
        dp[n] = 0;

        minimax(dp, n-1, n, stoneValue); 
        int ans = dp[0];
        if(ans > 0) return "Alice";
        else if(ans < 0) return "Bob";
        else return "Tie";
    }
};