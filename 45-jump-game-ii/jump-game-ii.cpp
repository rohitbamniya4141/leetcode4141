class Solution {
public:
    int solve(vector<int>&dp, int i, int n, vector<int>&nums){
        if(i > n-1) return 0;
        if(i == n-1) return dp[i] = 0;
        if(dp[i] != -1) return dp[i];
        int ans = 10000;
        for(int j = 1; j <= nums[i]; j++){
            int c = 1 + solve(dp, i+j, n, nums);
            ans = min(ans,c);
        } 
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        int ans = solve(dp, 0, n, nums);
        return dp[0];
    }
};