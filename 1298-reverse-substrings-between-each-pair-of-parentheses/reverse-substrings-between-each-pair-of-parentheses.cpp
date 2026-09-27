class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        int i = 0;
        string temp = "";
        while(i < s.size()){
            while(i < s.size() && s[i] != ')'){
                st.push(s[i]);
                i++;
            }
            i++;
            temp = "";
            while(!st.empty() && st.top() != '('){
                temp += st.top();
                st.pop();
            }
            bool rev = true;
            if(!st.empty() && st.top() == '('){
                rev = false;
                st.pop();
            }
            if(rev) reverse(temp.begin(), temp.end());
            for(int i = 0; i < temp.size(); i++){
                st.push(temp[i]);
            }
        }
        temp = "";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};