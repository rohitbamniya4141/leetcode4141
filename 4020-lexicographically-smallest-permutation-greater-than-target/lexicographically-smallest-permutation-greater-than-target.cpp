class Solution {
public:
    bool solve(vector<int>&mp, string& s, string target, int idx, bool greater, string& word){
        if(idx == target.size()){
            if(greater) return true;
            return false;
        }

        for(char t='a' ; t <= 'z'; t++){
            
            if(mp[t-'a'] <=0 ) continue;
            if(greater == false && t < target[idx]) continue;
            bool isgreater = greater;
            if(t > target[idx]) isgreater = true;
            word.push_back(t);
            mp[t-'a']--;
            bool ans = false;
            ans = solve(mp,s, target, idx+1, isgreater, word);
            if(ans) return true;

            word.pop_back();
            mp[t-'a']++;

        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int>mp(26,0);
        bool greater = false;
        for(char c:s){
            mp[c-'a']++;
        }
        string word = "";
        bool ans = false;
        ans = solve(mp, s, target, 0, greater, word);
        if(ans) return word;

        return "";
    }
};