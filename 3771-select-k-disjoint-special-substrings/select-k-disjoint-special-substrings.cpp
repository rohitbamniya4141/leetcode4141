class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);

        for(int i = 0; i < s.size(); i++){
            if(first[s[i]-'a'] == -1) first[s[i]-'a'] = i;
            last[s[i]-'a'] = i;
        }
        vector<pair<int,int>>intervals;
        for(int c = 0; c < 26; c++){
            int l = first[c];
            int r = last[c];
            if(l == -1) continue;
            bool ok = true;
            for(int i = l; i <= r; i++){
                if(first[s[i] - 'a'] < l){
                    ok = false;
                    break;
                }
                r = max(r, last[s[i] - 'a']);
            }

            if(ok &&!(l == 0 && r == s.size()-1)){
                intervals.push_back({r,l});
            }
        }
        sort(intervals.begin(), intervals.end());
        int prevend = -1;
        int cnt = 0;
        for(auto it:intervals){
            if(it.second > prevend){
                cnt++;
                prevend= it.first;
            }
        }
        return cnt >= k;
    }
};