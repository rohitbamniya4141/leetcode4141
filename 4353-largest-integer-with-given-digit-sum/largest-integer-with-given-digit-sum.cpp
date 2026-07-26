class Solution {
public:
    int largestInteger(int n, int s) {
        int m = pow(10,n);
        int t = 0;
        int ans = -1;
        while(t < m){
            int temp = t;
            int sum = 0;
            while(temp > 0){
                sum += temp%10;
                temp = temp/10;
            }
            if(sum == s){
                ans = max(t, ans);
            }
            t++;
        }
        return ans;
    }
};