class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i = 0; i < roads.size(); i++){
            int src = roads[i][0];
            int dest = roads[i][1];
            int w = roads[i][2];
            adj[src].push_back({dest,w});
            adj[dest].push_back({src,w});
        }
        int ans = INT_MAX;
        vector<bool>vis(n+1, false);
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 0; i < adj[curr].size(); i++){
                if(!vis[adj[curr][i].first]) {
                    q.push(adj[curr][i].first);
                    vis[(adj[curr][i].first)] = true;
                }
                ans = min(adj[curr][i].second, ans);
            }
        }
    return ans;
    }
};