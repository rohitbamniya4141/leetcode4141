class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int temp = 0;
        int seq = 1;
        int prev = nums[0];
        int sum = nums[0];
        int s = 1;
        int ans = sum;
        mp[prev]++;
        for(int i = 1; i < n; i++){
            mp[nums[i]]++;
            if(prev+1 == nums[i]){
                seq++;
                sum+=nums[i];
                ans = max(sum, ans);
                prev = nums[i];
            }
            else{
                ans = max(sum, ans);
                prev = -10;
            }

            
        }
    
        while(true){
            if(!mp.count(ans)){
                return ans;
            }
            ans++;
        }
    }
};