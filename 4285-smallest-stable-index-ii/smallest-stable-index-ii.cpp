class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ps(n);
        vector<int>ss(n);
        ps[0] = nums[0];
        ss[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            if(nums[i] > ps[i-1]){
                ps[i] = nums[i];
            }
            else{
                ps[i] = ps[i-1];
            }
        }

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < ss[i+1]){
                ss[i] = nums[i];
            }
            else{
                ss[i] = ss[i+1];
            }
        }

        for(int i = 0; i < n; i++){
            if(ps[i]-ss[i] <= k) return i;
        }
        return -1;
    }
};