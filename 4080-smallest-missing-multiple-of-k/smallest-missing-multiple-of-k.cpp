class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int j=1;
        while(true){
            if(!mp[k*j]){
                return k*j;
                break;
            }
            j++;
        }
        return 0;
    }
};