class Solution {
public:
    const long long MOD = 1e9 +7;
    long long modpow(long long x, long long y){
        
        long long ans = 1;
        while(y>0){
            if(y&1){
                ans = (ans*x)%MOD;
            }
            x = (x*x)%MOD;
            y>>=1;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(long long num : nums){
            int width = num%10;
            long long d = num/10;
            int digits = 0;
            long long t = d;
            while(t>0){
                digits++;
                t = t/10;
            }

            long long div = 1;
            for(int i = 0; i < digits-width; i++){
                div*= 10;
            }

            long long x = d/div;
            long long y = d%div;

            ans = (ans + modpow(x, y))%MOD;
        }
        return ans;
    }
};