class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long>dp(26, 0);
        long long MOD = 1e9 +7;
        long long total = 0;
        long long add = 0;
        for(char c:s){
            add = (1+total-dp[c-'a'])%MOD;
            dp[c-'a'] = (1+total)%MOD;
            total = (total+add+MOD)%MOD;
        }
        return total;
    }
};