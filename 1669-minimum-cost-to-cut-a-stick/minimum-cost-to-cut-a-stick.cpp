class Solution {
public:
    int minCost(int n, vector<int>& c) {
        vector<int>cuts;
        cuts.push_back(0);
        for(int i = 0; i < c.size(); i++){
            cuts.push_back(c[i]);
        }
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int t = cuts.size();
        vector<vector<long long>>dp(t+1, vector<long long>(t+1, LLONG_MAX));

        for(int i = 0; i <= t; i++){
            for(int j = 0; j <=t; j++){
                if(j - i <= 1){
                    dp[i][j] = 0;
                }
            }
        }
        for(int gap = 2 ; gap < t; gap++){
            for(int i = 0; i+gap<t; i++){
                int j = i+gap;
                int cost = cuts[j]-cuts[i];
                for(int k = i+1; k <j; k++){
                    dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k][j] + 1LL*cost));
                }
            }
        }

        return (int)dp[0][t-1];
    }
};