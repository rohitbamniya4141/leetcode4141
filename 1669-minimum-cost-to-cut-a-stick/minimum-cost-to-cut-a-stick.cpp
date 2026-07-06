class Solution {
public:
    long long solve(int range1, int range2, vector<int>& cuts, vector<vector<int>>&dp){
        int cost = cuts[range2]-cuts[range1];
        if(dp[range1][range2] != -1) return dp[range1][range2];
        if(range2 - range1 <= 1){
            return dp[range1][range2] = 0;
        }
        
        long long res = LLONG_MAX;
        for(int k = range1+1; k <= range2-1; k++){
            int cut = cuts[k];
            res = min(res, (solve(range1, k, cuts, dp) + solve(k, range2, cuts, dp) + cost));
        }
        return dp[range1][range2] = res;
    }
    int minCost(int n, vector<int>& c) {
        vector<int>cuts;
        cuts.push_back(0);
        for(int i = 0; i < c.size(); i++){
            cuts.push_back(c[i]);
        }
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(cuts.size(), vector<int>(cuts.size(), -1));
        return (int)solve(0, cuts.size()-1, cuts, dp);
    }
};