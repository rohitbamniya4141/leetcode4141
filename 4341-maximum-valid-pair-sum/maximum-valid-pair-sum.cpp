class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        int m = nums[0];
        for(int j = k ; j < n; j++){
            m = max(m, nums[j-k]);
            ans = max(ans, m+nums[j]);
        }
        return ans;
    }
};