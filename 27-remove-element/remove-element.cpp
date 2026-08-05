class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        int s = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == val) cnt++;
        }
        while(i < n){
            if(nums[i] == val){
                int end = i;
                while(end < n && nums[end] == val){
                    end++;
                }
                while(i < n && end < n){
                    nums[i] = nums[end];
                    end++;
                    while(end < n && nums[end] == val) end++;
                    i++;
                }
            }
            i++;
        }
        return n-cnt;
    }
};