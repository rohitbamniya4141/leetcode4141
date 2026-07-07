class Solution {
public:
    long long sumAndMultiply(int n) {
        long long mul = 1;
        long long sum = 0;
         int num = 0;
        while(n){
            int curr = n%10;

            if(curr != 0){
                num = curr*mul + num;
                mul = mul*10;
                sum+=curr;
            }
            n = n/10;
        }
        return sum*num;
    }
};