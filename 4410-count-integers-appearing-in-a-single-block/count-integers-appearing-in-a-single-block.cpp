class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt = 0;
        int i = 0;
        int n = nums.size();
        
        unordered_map<int,int>mp;
        while(i < nums.size()){
            int t = nums[i];
                while(i < n && nums[i] == t){
                    i++;
                }
                mp[t]++;
        }
        for(auto it:mp){
            if(it.second == 1){
                cnt++;
            }
        }
        return cnt;
    }
};