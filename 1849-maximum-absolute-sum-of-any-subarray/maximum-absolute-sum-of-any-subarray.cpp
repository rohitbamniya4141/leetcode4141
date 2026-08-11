class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxians = nums[0], bestending = 0;
        for(int i = 0; i < nums.size(); i++){
            int v1 = bestending + nums[i];
            int v2 = nums[i];
            bestending = max(v1,v2);
            maxians = max(maxians, bestending);
        }
        int minians = nums[0];
        bestending = 0;
        for(int i = 0; i < nums.size(); i++){
            int v1 = bestending + nums[i];
            int v2 = nums[i];
            bestending = min(v1,v2);
            minians = min(minians, bestending);
        }
        return max(abs(minians), maxians);
    }
};