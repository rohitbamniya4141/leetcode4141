class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        string ans;
        
        int m = str1.size(), n = str2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >=0 ;j--){
                if(str1[i] == str2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        int i = 0, j =0;
        while(i < m && j < n){
            if(str1[i] == str2[j]){
                ans+= str1[i];
                i++;
                j++;
            }
            else{
                if(dp[i+1][j] > dp[i][j+1]){
                    i++;
                }
                else{
                    j++;
                }
            }
        }

        string scs = "";
        int s1 = 0, s2 =0;
        for(auto it : ans){
            while(s1 < m && str1[s1] != it){
                scs+= str1[s1];
                s1++;
            }
            s1++;
            while(s2 < n && str2[s2] != it){
                scs+= str2[s2];
                s2++;
            }
            s2++;
            scs+= it;
        }
            while(s1 < m ){
                scs+= str1[s1];
                s1++;
            }
            while(s2 < n ){
                scs+= str2[s2];
                s2++;
            }
    return scs;
    }
};