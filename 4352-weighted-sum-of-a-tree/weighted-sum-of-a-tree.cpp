class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>>children(n);
        for(int i = 1; i < n; i++){
            children[parent[i]].push_back(i);
        }
        vector<int>depth(n);
        queue<int>q;
        q.push(0);
        depth[0] = 1;
        int h = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            h = max(depth[node], h);
            for(auto it: children[node]){
                depth[it] = depth[node]+1;
                q.push(it);
            }
        }
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += 1LL*(nums[i]) * (h-depth[i]+1);
        }
        return ans;
    }
};