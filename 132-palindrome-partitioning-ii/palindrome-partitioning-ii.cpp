class Solution {
public:
    bool ispalindrome(string&s, int i, int j){
        
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string&s, int i, int j, vector<vector<int>>&dp){
        if(i >= j){
            return 0;
        }
        if(ispalindrome(s, i, j)){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k <= j-1; k++){
            if(ispalindrome(s, i, k)){
                int p2 = solve(s, k+1, j, dp);
                ans = min(ans, p2 + 1);
            }
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        return solve(s, 0, s.size()-1, dp);
    }
};