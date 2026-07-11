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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
         parent.resize(n+1);
        rank.assign(n+1, 0);
        for(int i = 0 ; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0 ; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            if(find(src) != find(dest)){
                Union(src, dest);
            }
            else{
                return edges[i];
            }
        }

       
        return {};
    }
};