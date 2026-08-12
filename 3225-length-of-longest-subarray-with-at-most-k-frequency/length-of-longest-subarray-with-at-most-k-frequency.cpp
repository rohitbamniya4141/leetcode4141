class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start=0,end=0,ans=0,sum=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        while(end<n){
         if(mp[nums[end]]<k){
            mp[nums[end]]++;
            end++;
         }
         else{
          /*  for(auto it:mp){
                sum+=it.second;
            }
                ans=max(ans,sum);
               if(mp[nums[start]]>0) mp[nums[start]]--;
                sum=0;
                start++;
                mp[nums[end]]++;
              for(auto it:mp){
                sum+=it.second;
            }
            ans=max(ans,sum);
            if(mp[nums[end]]<k) end++;
                
            
         }
            sum=0;
        }
     
        for(auto it:mp){
            sum+=it.second;
        }
        ans=max(sum,ans); */
        ans=max(ans,end-start);
        mp[nums[start]]--;
        start++;
        if(mp[nums[end]]<k) {
            mp[nums[end]]++;
            end++;
        }
         }
        }
         for(auto it:mp){
            sum+=it.second;
        }
        return max(sum,ans);
    }
};