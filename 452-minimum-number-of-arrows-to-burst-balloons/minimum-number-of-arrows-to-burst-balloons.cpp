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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp());
        int cnt = 0;
        long long last = -(pow(2,31))-1;
        for(auto it: points){
            long long st = 1LL*it[0];
            long long end = 1LL*it[1];
            if(last < st){
                cnt++;
                last = end;
            }
        }
        return cnt;
    }
};