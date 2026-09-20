class Solution {
public:
    int reverseDegree(string s) {
        int req=0,ans=0,prod=0;
     for(int i=0;i<s.size();i++){
         req=26-(s[i]-'a');
         prod++;
         ans+=prod*req;
     }
        return ans;
    }
};