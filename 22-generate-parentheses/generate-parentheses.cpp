class Solution {
public:
    void func(int ug, int pg, string s, vector<string>& ans, int n){
        if(ug > n || pg > n) return;
        if(ug < pg) return;
        if(ug == n && pg == n) {
            ans.push_back(s);
            return;
        }

        func(ug+1, pg, s+'(', ans, n);
        func(ug, pg+1, s+')', ans, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int ug = 0, pg = 0;
        string s = "";
        func(ug, pg, s, ans, n);
        return ans;
    }
};