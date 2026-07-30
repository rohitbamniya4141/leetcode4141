class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        while(n >= 0){
            int temp = n;
            int cnt = 0;
            while(temp > 0){
                temp = temp&(temp-1);
                cnt++;
            }
            n--;
            ans.insert(ans.begin(), cnt);
        }
        return ans;
    }
};