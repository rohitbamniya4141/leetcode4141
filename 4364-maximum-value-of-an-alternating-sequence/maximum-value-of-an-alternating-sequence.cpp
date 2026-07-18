class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        int peak = n/2;
        long long ans1 = 1LL*s, ans2 = 1LL*s;
        if(peak > 0){
            ans1 = 1LL*s+ 1LL*peak*(m) - 1LL*(peak-1);
        }

        peak = (n-1)/2;

        if(peak > 0){
            ans2 = 1LL*s+ 1LL*peak*(m-1); 
        }

        if(ans1 >= ans2) return ans1;
        return ans2;
    }
};