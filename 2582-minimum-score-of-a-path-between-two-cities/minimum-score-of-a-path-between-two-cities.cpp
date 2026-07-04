class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<pair<int,int>>>adj;
        int last =1;
        for(int i = 0; i < roads.size(); i++){
            int src = roads[i][0];
            int dest = roads[i][1];
            int w = roads[i][2];
            adj[src].push_back({dest,w});
            adj[dest].push_back({src,w});
        }
        int ans = INT_MAX;
        vector<bool>vis(n+1,0);
        queue<int>q;
        vis[1]=1;
        q.push(1);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto d : adj[curr]){
                ans = min(ans,d.second);
                if(!vis[d.first]){
                    q.push(d.first);
                    vis[d.first] = 1;
                }
            }
        }
    return ans;
    }
};