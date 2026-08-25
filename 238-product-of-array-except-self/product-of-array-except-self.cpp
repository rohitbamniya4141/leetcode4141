class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero =0;
        int idx = 0;
        int main = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                idx = i;
                zero++;
            }
            else main *= nums[i];
        }
        int n = nums.size();
        vector<int>ans(n, 0);

        if(zero > 1) return ans;
        else if(zero == 1){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0) {
                    ans[i] = main;
                }
            }
            
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                ans[i] = main/nums[i];
            }
        }

        
    return ans;
    }
};