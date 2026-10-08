class Solution {
public:
    string removeOuterParentheses(string s) {
        int start=0,end=-1,count=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                end=i;
                if(end-start>2){
                    ans+=s.substr(start+1,end-start-1);
                    
                }
                start=end+1;
            }
        }
        return ans;
    }
    
};