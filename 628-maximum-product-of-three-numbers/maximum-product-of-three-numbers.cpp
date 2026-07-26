class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MIN,n=nums.size()-1;
        ans=max(ans,nums[n]*nums[n-1]*nums[n-2]);
        ans=max(ans,nums[n]*nums[1]*nums[0]);
        return ans;
    }
};