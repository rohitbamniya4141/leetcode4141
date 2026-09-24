class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i< nums.size(); i++){
            int m = nums[i];
            int s = 0;
            while(m >0){
                s += m%10;
                m=m/10;
            }
            if(s == i) return i;
        }

        return -1;
    }
};