class Solution {
public:
    vector<int> parent, rank1;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (rank1[pa] > rank1[pb])
            parent[pb] = pa;
        else if (rank1[pa] < rank1[pb])
            parent[pa] = pb;
        else {
            parent[pb] = pa;
            rank1[pa]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        parent.resize(n);
        rank1.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);

                edges.push_back({wt, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int ans = 0;

        for (auto &e : edges) {

            int wt = e[0];
            int u = e[1];
            int v = e[2];

            if (find(u) != find(v)) {
                Union(u, v);
                ans += wt;
            }
        }

        return ans;
    }
};