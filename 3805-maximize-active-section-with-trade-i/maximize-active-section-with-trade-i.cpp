class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
        int n = s.size();
        int ones = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') ones++;
        }



        int i = 0;
        int prev = 0, curr = 0;
        while(i < n && s[i] == '0'){
            curr++;
            i++;
        }
        int ans = 0;
        while(i < n){
            while(i < n && s[i] == '1'){
                i++;
            }
            if(i == n && prev == 0) return ones;
            prev = curr;
            curr = 0;
            while(i < n && s[i] == '0'){
                curr++;
                i++;
            }
            ans = max(ans, curr+prev);
            if(i == n && prev == 0) return ones;
        }
        return ans+ones;
    }
};