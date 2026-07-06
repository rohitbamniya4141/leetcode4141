class Solution {
public:
    struct cmp{
        bool operator()(vector<int>& a, vector<int>&b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        }
    };
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int n = intervals.size();
        int i = 0;
        int j = 1;
        int cnt = 0;
        
        while(i < n && j < n){
            int sti = intervals[i][0];
            int endi = intervals[i][1];
            int stj = intervals[j][0];
            int endj = intervals[j][1];
            if(sti <= stj && endi >= endj){
                j++;
            }
            else{
                cnt++;
                i = j;
            }
        }
        if(i < n) cnt++;
        return cnt;
    }
};