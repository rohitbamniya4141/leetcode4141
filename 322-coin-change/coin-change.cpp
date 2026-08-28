class Solution {
public:
    int solve(int amt, vector<int>& coins, vector<int>& dp){
        if(amt == 0) return 0;
        if(dp[amt] != -1) return dp[amt];
        int ans = INT_MAX;
        for(auto coin : coins){
            if(amt-coin >= 0){
                int sub = solve(amt-coin, coins, dp);
                if(sub != INT_MAX){
                    ans = min(ans,1+sub);
                }
            }
        }
        return dp[amt] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        int ans = solve(amount, coins, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};