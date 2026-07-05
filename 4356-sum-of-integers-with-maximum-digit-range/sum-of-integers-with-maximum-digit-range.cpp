class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size();i++){
            int num = nums[i];
            int mx = INT_MIN;
            int mn = INT_MAX;
            if(num == 0){
                mx =0;
                mn = 0;
            }
            while(num > 0){
                int c = num%10;
                mx = max(mx, c);
                mn = min(mn, c);
                num = num/10;
            }
             ans = max(ans,mx-mn);
        }
        int sum = 0;
        for(int i = 0; i < nums.size();i++){
            int num = nums[i];
            int mx = INT_MIN;
            int mn = INT_MAX;
            if(num == 0){
                mx =0;
                mn = 0;
            }
            while(num > 0){
                int c = num%10;
                mx = max(mx, c);
                mn = min(mn, c);
                num = num/10;
            }
            int curr = mx-mn;
            if(ans == curr){
                sum+= nums[i];
            }
            
        }
    
        return sum;
    }
};