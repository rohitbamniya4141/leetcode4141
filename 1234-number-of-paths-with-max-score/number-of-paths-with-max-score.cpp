class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board.size();
        long long mod = 1e9 + 7;
        vector<vector<pair<long long, long long>>>dp(m+1, vector<pair<long long,long long>>(n+1,{-1,-1}));
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                char curr = board[i][j];
                long long cost = 0;
               
                if(curr == 'X') {
                    cost = -1;
                    dp[i][j] = {-1, 0};
                    continue;
                }
                if(curr == 'S'){
                    dp[i][j] = {0,1};
                    continue;
                }
                if(isdigit(curr)) cost = 1LL*(curr - '0');
                auto c1 = dp[i][j+1];
                auto c2 = dp[i+1][j+1];
                auto c3 = dp[i+1][j];
                long long mx = max(c1.first,max(c2.first, c3.first));
                long long path = 0;
                
                if(mx!= -1 && mx == c1.first) path= (path + 0LL+c1.second)%mod;
                if(mx!= -1 && mx == c2.first) path = (path + 0LL+c2.second)%mod;
                if(mx!= -1 && mx == c3.first) path = (path + 0LL+c3.second)%mod;
                
                if(j == n-1 && dp[i+1][j].first == -1){
                    dp[i][j] = {-1, -1};
                }
                else if(curr == 'E'){
                    dp[i][j] = {mx%mod,path};
                }
                else dp[i][j] = {(mx+cost)%mod,path};
            }
        }
        int a = dp[0][0].first;
        int b = dp[0][0].second;
        if(b == 0) a = 0;
        
        return {a,b};
    }
};