class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m = t.size();
        int n = s.size();
        vector<int>pre(n,-1);
        vector<int>suff(n,m);

        if(n > m) return false;
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < m && s[i] != t[j]) j++;

            if(j == m) break;
            pre[i] = j;
            j++;
        }
        if(pre[n-1] != -1) return true;
        j = m-1;

        for(int i = n-1; i >= 0; i--){
            while(j >= 0 && s[i] != t[j]) j--;

            if(j < 0) break;
            suff[i] = j;
            j--;
        }

        for(int i = 0; i < n; i++){
            int left =0, right = 0;
            if(i == 0){
                left = -1;
            }
            else{
                left = pre[i-1];
            }

            if(i == n-1){
                right = m;
            }
            else {
                right = suff[i+1];
            }

            if(i!=0 && left == -1) continue;
            if(i != n-1 && right == m) continue;

            if(left + 1 < right) return true;
        }
        return false;
    }
};