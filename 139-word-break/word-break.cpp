class Solution {
public:
bool rec(string&s, int i, map<int, bool>&mp, vector<string>&wordDict){
    if(i==s.size()) return 1;

    if(mp.find(i)!=mp.end()) return mp[i];
    for(auto w:wordDict){
        int l=w.size();
        if(i+l<=s.size() && s.substr(i, l)==w){
            if(rec(s, i+l, mp, wordDict)){
                return mp[i]=1;
            }
        }
    }
    return mp[i]=0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        map<int, bool> mp;
        return rec(s, 0, mp, wordDict);
    }
};