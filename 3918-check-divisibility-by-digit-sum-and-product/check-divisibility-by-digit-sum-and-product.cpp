class Solution {
public:
    bool checkDivisibility(int n) {
        vector<int>num;
        int q=n;
        int s1=0,s2=1;
     while(n!=0){
         num.push_back(n%10);
         n=n/10;
     }   
        for(int i=0;i<num.size();i++){
            s1=s1+num[i];
            s2=s2*num[i];
        }
        if(q%(s1+s2)==0) return true;
        return false;
    }
};