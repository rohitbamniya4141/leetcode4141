class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool allzero = true;
        int x = 0;
        for(auto it:nums){
            x = x^it;
            if(it != 0){
                allzero = false;
            }
        }
        int n = nums.size();
        if(x != 0) return n;
        if(x == 0){
            if(allzero){
                return 0;
            }
            else return n-1;
        }
        return 0;
    }
};