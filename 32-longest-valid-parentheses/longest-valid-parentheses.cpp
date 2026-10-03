class Solution {
public:
    int longestValidParentheses(string s) {
        int l = s.size();
        stack<int>st;
        st.push(-1);
        int i = 0;
        int ans = 0;
        while(i < s.size()){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans = max(ans, i-st.top());
                }
            }
            i++;
        }

    return ans;
    }
};