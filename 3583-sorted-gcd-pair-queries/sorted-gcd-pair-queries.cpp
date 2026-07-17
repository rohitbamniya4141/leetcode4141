class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);

        for(int x : nums)
            freq[x]++;


        vector<long long> exact(mx + 1, 0);


        // count exact gcd
        for(int g = 1; g <= mx; g++){

            long long cnt = 0;

            // numbers divisible by g
            for(int multiple = g; multiple <= mx; multiple += g){
                cnt += freq[multiple];
            }

            // total pairs having gcd multiple of g
            exact[g] = cnt * (cnt - 1) / 2;
        }


        // remove multiples (inclusion-exclusion)
        for(int g = mx; g >= 1; g--){

            for(int multiple = 2*g; multiple <= mx; multiple += g){

                exact[g] -= exact[multiple];

            }
        }


        // prefix sum
        vector<long long> prefix(mx + 1);

        for(int i = 1; i <= mx; i++){

            prefix[i] = prefix[i-1] + exact[i];

        }


        vector<int> ans;


        for(long long q : queries){

            int gcd = lower_bound(prefix.begin()+1,
                                  prefix.end(),
                                  q+1)
                      - prefix.begin();

            ans.push_back(gcd);
        }


        return ans;
    }
};