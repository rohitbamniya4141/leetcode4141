class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        if(k==nums.size()){
            return *max_element(nums.begin(),nums.end());
        }
        
        for(int i=0;i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int>temp=nums;
         if(k==1){
           sort(temp.begin(),temp.end(),greater<int>());
           for(int i=0;i<temp.size();i++){
             int m=temp[i];
             if(mp[m]==1) return m;
           }
        }

        if(mp[nums[0]]==1||mp[nums[nums.size()-1]]==1){
            if(mp[nums[0]]==1&&nums[0]>nums[nums.size()-1]){
             return nums[0];
            } 
            else if(mp[nums[nums.size()-1]]==1){
               return nums[nums.size()-1];
            }
            else return nums[0];
        } 
       
        
        return -1;
    }
};