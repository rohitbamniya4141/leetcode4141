class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = nums[0];
        int n = nums.size();
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            curr = nums[i];
            if(n-i-1 <= curr || n-i-1 <= jump) return true;
            jump = max(jump, curr);
            if(jump <= 0) return false;
            jump--;
        }

        return false;
    }
};