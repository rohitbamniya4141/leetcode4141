class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};
        vector<vector<int>>dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = grid[0][0];
        using ppf = pair<int,pair<int,int>>;
        priority_queue<ppf,vector<ppf>, greater<ppf>>pq;
        int cost = grid[0][0];
        pq.push({cost,{0,0}});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            cost = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if(cost > dis[r][c]) continue;

            for(int k = 0; k < 4; k++){
                int nr = r + x[k];
                int nc = c + y[k];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                int newcost = cost + grid[nr][nc];
                if(newcost < dis[nr][nc]){
                    dis[nr][nc] = newcost;
                    pq.push({newcost,{nr,nc}});
                }
            }

        }
        if(dis[m-1][n-1] >= health) return false;
        return true;
    }
};