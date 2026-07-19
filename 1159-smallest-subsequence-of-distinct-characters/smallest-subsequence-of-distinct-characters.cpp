class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>mp(26,0);

        for(int i = 0; i < s.size(); i++){
            mp[s[i]-'a']++;
        }
        vector<int>vis(26, 0);
        stack<int>st;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            mp[c-'a']--;
            if(vis[c-'a']){
                continue;
            }
            while(!st.empty() && c < st.top() && mp[st.top() - 'a'] > 0){
                vis[st.top()-'a'] = false;
                st.pop();
            }
            st.push(c);
            vis[c-'a'] = 1;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};