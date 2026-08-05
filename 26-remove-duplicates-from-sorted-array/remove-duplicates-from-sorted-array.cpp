class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int st = 0;
        int end = 1;
        int cnt = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        while(st < n && end < n){
            if(nums[st] == nums[end]){
                while(end < n && nums[st] == nums[end]){
                    end++;
                }
                st++;
               if(end < n) nums[st] = nums[end];
            }
            else{
                st++;
                end++;
            }
        }
        cnt = mp.size();
        return cnt;
    }
};