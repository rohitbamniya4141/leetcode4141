class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        // position of original index in sorted array
        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[a[i].second] = i;

        // far[i] = farthest index reachable in one jump
        vector<int> far(n);

        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j + 1 < n && a[j + 1].first - a[i].first <= maxDiff)
                j++;
            far[i] = j;
        }

        const int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = far[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q : queries){

            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u > v) swap(u,v);

            // same node
            if(u == v){
                ans.push_back(0);
                continue;
            }

            // cannot even move
            if(far[u] == u){
                ans.push_back(-1);
                continue;
            }

            int jumps = 0;

            for(int k = LOG-1; k >= 0; k--){

                if(up[k][u] < v){
                    u = up[k][u];
                    jumps += (1<<k);
                }
            }

            if(far[u] >= v)
                ans.push_back(jumps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};