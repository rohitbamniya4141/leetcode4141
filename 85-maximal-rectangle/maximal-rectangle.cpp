class Solution {
public:
    // aditya verma
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nextsm(heights.size(), 1);
        vector<int>prevsm(heights.size(), 1);
        stack<pair<int,int>>nst;
        stack<pair<int,int>>pst;
        nst.push({heights[n-1], n-1});
        for(int i = n-2; i >=0; i--){
            while(!nst.empty() && nst.top().first >= heights[i]){
                nst.pop();
            }
            if(!nst.empty()) nextsm[i] = nst.top().second-i;
            else nextsm[i] = n-i;

            nst.push({heights[i], i});
        }
        pst.push({heights[0], 0});
        for(int i = 1; i < n; i++){
            while(!pst.empty() && pst.top().first >= heights[i]){
                pst.pop();
            }
            if(!pst.empty()) prevsm[i] = i - pst.top().second;
            else prevsm[i] = i+1;

            pst.push({heights[i], i});
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, (prevsm[i]+nextsm[i]-1)*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int>temphist(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] != '0') temphist[j] = temphist[j]+(matrix[i][j]-'0');
                else temphist[j] = 0;
            }
            ans = max(ans, largestRectangleArea(temphist));
        }
        return ans;
    }
};