class Solution {
public:
    vector<int>getprimefactors(int n){
        vector<int>factors;
        for(int p = 2; p*p <= n; p++){
            if(n%p == 0){
                factors.push_back(p);
                while(n%p == 0){
                    n= n/p;
                }
            }
        }
        if(n > 1){
            factors.push_back(n);
        }
        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<vector<int>>factors(n);
        for(int i = 0; i < nums.size(); i++){
            factors[i] = getprimefactors(nums[i]);
        }
        int distinct = 0;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++){
            for(auto it:factors[r]){
                if(mp[it] == 0){
                    distinct++;
                }
                mp[it]++;
            }

            while(distinct > k){
                for(auto it:factors[l]){
                    mp[it]--;
                    if(mp[it] == 0){
                        distinct--;
                    }
                }
                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};