class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>>&dp){
        // base case
        int m = s.size(), n = p.size();
        if(j == n) return i == m;

        if(dp[i][j] != -1) return dp[i][j];

        bool match = ((i < m )&& (p[j] == '.' || s[i] == p[j]));

        if(j+1 < n && p[j+1] == '*'){
            bool skip = solve(s, p, i, j+2, dp);
            bool take = false;

            if(match){
                take = solve(s, p, i+1, j, dp);
            }
            return dp[i][j] = skip||take;
        }

        if(match){
            return dp[i][j] = solve(s, p, i+1, j+1, dp);
        }

        return dp[i][j] = false;

    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        return solve(s, p, 0, 0, dp);
    }
};