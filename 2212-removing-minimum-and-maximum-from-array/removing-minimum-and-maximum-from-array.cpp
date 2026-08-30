class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        int minidx =0, maxidx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mini > nums[i]){
                mini = nums[i];
                minidx = i;
            }
            if(maxi < nums[i]){
                maxi = nums[i];
                maxidx = i;
            }
        }
        bool yes = false;
        if(minidx < maxidx) yes = true;
        if(yes){
            int c1 = (minidx-0+1)+(n-maxidx);
            int c2 = (minidx-0+1)+(maxidx-minidx);
            int c3 = (n-maxidx)+(maxidx-minidx);
            return min(c1,min(c2,c3));
        }
        else{
            int c1 = (maxidx-0+1)+(n-minidx);
            int c2 = (maxidx-0+1)+(minidx-maxidx);
            int c3 = (n-minidx)+(minidx-maxidx);
            return min(c1,min(c2,c3));
        }
    }
};