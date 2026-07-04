class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int n = nums.size()/2;
        int mid = n;
        if(mp[nums[mid]] == 1) return true;
        return false;
    }
};