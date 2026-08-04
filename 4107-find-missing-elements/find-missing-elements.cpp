class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        set<int> s(nums.begin(), nums.end());
        vector<int> ans;
        for(int n : nums){
            mini = min(n, mini);
            maxi = max(n, maxi);
        }
        for(int i = mini; i<= maxi; i++){
            if(s.find(i) == s.end()) ans.push_back(i);
        }
        return ans;
    }
};