class Solution {
public:
    string smallestPalindrome(string s) {
        
        vector<int>mp(26,0);
        string ans = s;
        for(auto it:s){
            mp[it-'a']++;
        }
        int i = 0;
        int n = s.size();
        int pos = 0;
        while(i < 26){
            if(mp[i] <= 0){
                i++;
                continue;
            }
            if(mp[i]%2 == 0){
                ans[pos] = i+'a';
                ans[n-1-pos] = i+'a';
                mp[i]-=2;
                if(mp[i] <= 0) i++;
                pos++;
            }
            else{
                ans[n/2] = i+'a';
                mp[i]--;
                if(mp[i] <= 0) i++;
            }
        }
        return ans;
    }
};