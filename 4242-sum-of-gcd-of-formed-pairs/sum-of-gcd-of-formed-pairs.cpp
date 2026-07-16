class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>mx;
        vector<int>prefgcd;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            maxi = max(nums[i], maxi);
            mx.push_back(maxi);
            int ngcd = gcd(mx[i], nums[i]);
            prefgcd.push_back(ngcd);
        }
        sort(prefgcd.begin(), prefgcd.end());
        int i = 0, j = nums.size()-1;
        long long sum = 0;
        while(i < j){
            sum += 1LL*gcd(prefgcd[i], prefgcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};