class Solution {
public:
    string binary(int t){
        string ans = "";
        while(ans.size() < 8){
            ans = char((t%2) + '0') + ans;
            t = t/2;
        }
        return ans;
    }
    bool isPalindromic(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            int t = (unsigned char)s[i];
            ans += binary(t);
        }
        
        int l = 0, r= ans.size()-1;
        while(l <= r){
            if(ans[l] != ans[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};