class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<char,int>mp;
        while(r < s.size() && l <= r){
            while(r < s.size() && mp[s[r]] <= 1){
                mp[s[r]]++;
                r++;
                ans = max(ans, r-l);
            }
            while(l <= r && mp[s[r]] >= 2){
                mp[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};