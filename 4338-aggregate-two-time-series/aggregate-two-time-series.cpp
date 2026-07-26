class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i = 0, j = 0;
        int val1, val2;
        vector<vector<int>>ans;
        int idx;
        int m = series1.size(), n = series2.size();
        while(i < m && j < n){
            
            if(series1[i][0] < series2[j][0]){
                idx = series1[i][0];
                val1 = series1[i][1];
                val2 = series2[j][1];
                i++;
            }
            else if(series1[i][0] == series2[j][0]){
                idx = series1[i][0];
                val1 = series1[i][1];
                val2 = series2[j][1];
                i++;
                j++;
            }
            else{
                idx = series2[j][0];
                val1 = series1[i][1];
                val2 = series2[j][1];
                j++;
                
            }

            ans.push_back({idx, val1+val2});
        }
        while(i < m){
            idx = series1[i][0];
            val1 = series1[i][1];
            val2 = 0;
            ans.push_back({idx, val1+val2});
            i++;
        }
        while(j < n){
            idx = series2[j][0];
            val1 = series2[j][1];
            val2 = 0;
            ans.push_back({idx, val1+val2});
            j++;
        }
    return ans;
    }
};