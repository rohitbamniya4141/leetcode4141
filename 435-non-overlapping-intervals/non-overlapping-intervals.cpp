class Solution {
public:
    struct cmp{
        bool operator()(vector<int>&a, vector<int>&b){
            if(a[1] == b[1]){
                return a[0] < b[0];
            }

            return a[1] < b[1];
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int lastend = -5*10000-1;
        int cnt = 0;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            int currst = intervals[i][0];
            int currend = intervals[i][1];
            if(currst < lastend){
                cnt++;
            }
            else lastend = currend;
        }
        return cnt;
    }
};