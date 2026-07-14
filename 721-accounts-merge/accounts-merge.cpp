class DSU{
    public:
    vector<int>parent, rank, size;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);

        for(int i = 0; i < n+1; i++){
            parent[i] = i;
        }
    }

    int find(int n){
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    void UnionByRank(int i, int j){
        int px = find(i);
        int py = find(j);

        if(px == py) return ;

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

    void UnionBySize(int i, int j){
        int px = find(i);
        int py = find(j);

        if(px == py) return ;

        if(size[px] >= size[py]){
            parent[py] = px;
            size[px] += size[py];
        }        
        else{
            parent[px] = py;
            size[py] += size[px];
        }
        
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int>mapemail_p;
       
        int n = accounts.size();
        DSU ds(n);
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapemail_p.find(mail) == mapemail_p.end()){
                    mapemail_p[mail] = i;
                }
                else{
                    ds.UnionByRank(mapemail_p[mail] , i);
                }
            }
        }

        unordered_map<int, vector<string>>mergedmail;
        for(auto it: mapemail_p){
            int node = ds.find(it.second);
            string mail = it.first;
            mergedmail[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(auto it: mergedmail){
            int node = it.first;
            vector<string>temp = it.second;
            
            sort(temp.begin(), temp.end());
            temp.insert(temp.begin(),accounts[node][0]);
            ans.push_back(temp);
        }
        return ans;
    }
};