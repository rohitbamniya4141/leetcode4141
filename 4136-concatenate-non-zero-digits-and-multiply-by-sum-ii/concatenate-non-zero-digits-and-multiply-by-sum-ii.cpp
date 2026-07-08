class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>arr;
        vector<int>index;
        vector<int>prefixsum;
        vector<long long>str;
        vector<int>ans;
        int sum = 0;
        long long strg = 0;
        prefixsum.push_back(0);
        str.push_back(0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '0'){
                arr.push_back(s[i]-'0');
                index.push_back(i);
                sum += s[i]-'0';
                strg = (10*strg+ s[i]-'0')%MOD;
                prefixsum.push_back(sum);
                str.push_back(strg);
            }
        }

        int m = arr.size();
        vector<long long>pow10(m+1,1);
        for(int i = 1; i <= m; i++){
            pow10[i] = (pow10[i-1]*10)%MOD;
        }
        for(int i = 0; i < queries.size(); i++){
            int fs = queries[i][0];
            int fe = queries[i][1];
            int st = lower_bound(index.begin(), index.end(), fs) - index.begin();
            int end = upper_bound(index.begin(), index.end(), fe) - index.begin() -1;

            if(st > end){
                ans.push_back(0);
                continue;
            }
            long long currsum = prefixsum[end+1] - prefixsum[st];
            int len = end-st+1;
            long long currstr = (str[end+1] - (str[st]*pow10[len])%MOD +MOD)%MOD;
            
            ans.push_back((currstr*currsum)%MOD);
        }
        return ans;
    }
};