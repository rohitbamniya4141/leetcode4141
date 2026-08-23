class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        int l1 = lower;
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            if(curr < lower){
                continue;
            }
            if(curr > upper){
                break;
            }
            if(curr > l1){
                ans.push_back({l1,curr-1});
            }
            if(curr >= l1){
                l1 = curr+1;
            }
        }
        if(l1 <= upper){
            ans.push_back({l1, upper});
        }
        return ans;
    }
};