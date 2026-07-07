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

    int solve(string&s, int i, int j, vector<int>&dp, vector<vector<bool>>&pal){
        if(i >= j){
            return 0;
        }
        if(ispalindrome(s, i, j)){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int k = i; k <= j-1; k++){
            if(pal[i][k]){
                int p2 = solve(s, k+1, j, dp, pal);
                ans = min(ans, p2 + 1);
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        vector<int>dp(s.size(), -1);
        vector<vector<bool>>pal(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(ispalindrome(s, i, j)){
                    pal[i][j] = true;
                }
            }
        }
        return solve(s, 0, s.size()-1, dp, pal);
    }
};