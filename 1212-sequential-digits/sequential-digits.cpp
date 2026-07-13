class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;

        for(int len = 2; len <= 9; len++){
            for(int start = 1; start <= 10-len; start++){
                int digit = 0;
                for(int i = start; i < start+len; i++){
                    digit = digit*10 + i;
                }

                if(digit >= low && digit <= high){
                    ans.push_back(digit);
                }
            }
        }
        return ans;
    }
};