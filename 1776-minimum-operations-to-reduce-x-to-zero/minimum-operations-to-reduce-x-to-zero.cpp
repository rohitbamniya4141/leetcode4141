class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int>temp(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            temp.push_back(nums[i]);
        }

        int i = 0, j= 0;
        int ms = INT_MAX;
        int sum = 0;
        while(j < temp.size()){
            while(j < temp.size()&& sum<x){
                sum+=temp[j];
                j++;
            }
            
            while(sum >= x && i <= j){
                if(sum == x && (i == 0 || j == 2 * n - 1 || (i < n && j >= n))) ms = min(ms, j-i);
                sum-= temp[i];
                i++;
            }

        }

        if(ms == INT_MAX || ms>nums.size()) return -1;
        return ms;

    }
};