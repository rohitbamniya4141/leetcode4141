class Solution {
public:
    bool check(int mid, vector<vector<int>>& edges, vector<bool>& online, long long k){
        int n = online.size();
        vector<vector<pair<int,int>>>adj(n);
        vector<int>indegree(n);
        for(int i = 0; i< edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            int w = edges[i][2];

            if(w < mid) continue;

            if(src!=0 && !online[src]) continue;
            if(dest!=n-1 && !online[dest]) continue;

            adj[src].push_back({dest,w});
            indegree[dest]++;
        }
        queue<int>q;
        for(int i =0; i < indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<long long>dist(n, LLONG_MAX);
        dist[0] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 0; i < adj[curr].size(); i++){
                int v = adj[curr][i].first;
                int w = adj[curr][i].second;
                if(dist[curr] != LLONG_MAX){
                    dist[v] = min(dist[curr] + w, dist[v]);
                }
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return dist[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int low = 0;
        int high = 0;
        for(int i = 0; i < edges.size(); i++){
            high = max(high, edges[i][2]);
        }
        int ans = -1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(check(mid, edges, online, k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};