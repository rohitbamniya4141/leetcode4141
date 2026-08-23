class Solution {
public:
    bool sumGame(string num) {
        int leftq = 0;
        int rightq = 0;
        int leftsum = 0;
        int rightsum = 0;
        for(int i = 0; i < num.size()/2; i++){
            if(num[i] == '?') leftq++;
            else leftsum += num[i]-'0';
        }
        for(int i = num.size()/2; i < num.size(); i++){
            if(num[i] == '?') rightq++;
            else rightsum += num[i]-'0';
        }
        int t = leftq+rightq;
        if((t>0) && (t)%2 != 0) return true;

        int finalleft = 9*leftq + 2*leftsum;
        int finalright = 9*rightq + 2*rightsum;

        if(finalleft == finalright) return false;

        return true;

    }
};