class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            mini = min(nums[i], mini);
            maxi = max(nums[i], maxi);
            mp[nums[i]]++;
        }
        for(int i = mini; i <= maxi; i++){
            if(!mp.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};