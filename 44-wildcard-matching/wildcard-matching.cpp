class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>>&dp){
        // base case
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >=0){
            for(int k = 0; k <=j; k++){
                if(p[k]!= '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //choices
        if((s[i] == p[j]) || (p[j] == '?')){
            return dp[i][j] = solve(s, p, i-1, j-1, dp);
        }
        else if(p[j] == '*'){
            bool c1 = solve(s, p, i-1, j, dp);
            bool c2 = solve(s, p, i, j-1, dp);
            return dp[i][j] = c1||c2;
        }
        else return dp[i][j] = false;

    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(s, p, s.size()-1, p.size()-1, dp);
    }
};