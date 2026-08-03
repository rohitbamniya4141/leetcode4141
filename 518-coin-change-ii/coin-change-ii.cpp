class Solution {
public:
    int solve(int i, int n, int curr, int total, vector<int> &coins, vector<vector<int>>&dp){
        if(curr == total){
            return 1;
        }
         if(i >= n || curr > total)
            return 0;

        if(dp[i][curr] !=-1) return dp[i][curr];
       

        int take = 0;
        if(INT_MAX-coins[i] >= curr && curr < total){
            take = solve(i, n, curr+coins[i], total, coins, dp);
        }
        int skip = solve(i+1, n, curr, total, coins, dp);
        
        return dp[i][curr] = take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int cnt = 0;
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return solve(0, n, 0, amount, coins, dp);
        
    }
};