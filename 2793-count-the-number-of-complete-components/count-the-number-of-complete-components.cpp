class Solution {
public:
    vector<int>parent, rank;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){
        int px = find(a);
        int py = find(b);

        if(px == py) return;

        if(rank[px] > rank[py]){
            parent[py] = px;
        }
        else if(rank[px] < rank[py]){
            parent[px] = py;
        }
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.assign(n, 0);
        for(int i = 0 ; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0 ; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            Union(src, dest);
        }

        unordered_map<int,int>edgecnt;
        unordered_map<int,int>nodecnt;

        for(int i = 0; i < n; i++){
            nodecnt[find(i)]++;
        }
        for(int i = 0 ; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            edgecnt[find(src)]++;
        }
        int cnt = 0;
        for(auto it: nodecnt){
            int node = it.second;
            int edg = edgecnt[it.first];
            if(node*(node-1)/2 == edg) cnt++;
        }
        return cnt;
    }
};