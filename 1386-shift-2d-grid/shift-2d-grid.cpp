class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        k = k % (r*c);
        vector<vector<int>>newm(r, vector<int>(c,0));
        int sr = k/c;
        int sc = k%c;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int idx = (i*c + j +k)%(r*c);

                newm[idx/c][idx%c] = grid[i][j];
            }
        }
    return newm;
    }
};