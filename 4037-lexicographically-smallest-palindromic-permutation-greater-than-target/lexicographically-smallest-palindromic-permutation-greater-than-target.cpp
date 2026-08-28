class Solution {
public:
    char midchar = '#';
    bool solve(vector<int>&mp, string& s, string target, int idx, bool greater, string& word, string& main){
        if(idx == s.size()/2){
            string right = word;
            main = word;
            reverse(right.begin(), right.end());
            if(midchar != '#'){
                main += midchar;
            }
            main += right;
            if(main > target){
                return true;
            }
            return false;
        }

        for(char t='a' ; t <= 'z'; t++){
            if(mp[t-'a'] <=0 ) continue;
            if(greater == false && t < target[idx]) continue;
            
            
            word.push_back(t);
            mp[t-'a']--;
            bool isgreater = greater || t > target[idx];
            bool ans = false;
            ans = solve(mp,s, target, idx+1, isgreater, word, main);
            if(ans) return true;

            word.pop_back();
            mp[t-'a']++;

        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int>mp(26,0);
        bool greater = false;
        for(char c:s){
            mp[c-'a']++;
        }
        int oddcnt = 0;
        vector<int>halfmp(26, 0);
        for(int i = 0; i < 26; i++){
            if(mp[i]%2 != 0){
                 oddcnt++;
                 midchar = i + 'a';
            }
            halfmp[i] = mp[i]/2;
        }
        
        string word = "";

        if(oddcnt > 1) return word;
        bool ans = false;
        string main = "";
        ans = solve(halfmp, s, target, 0, greater, word, main);
        if(ans) return main;

        return "";
    }
};