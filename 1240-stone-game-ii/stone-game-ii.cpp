class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suffix;
    int n;

    int solve(int i, int M)
    {
        if(i>=n)
            return 0;

        if(dp[i][M]!=-1)
            return dp[i][M];

        int ans=0;

        for(int x=1;x<=2*M;x++)
        {
            if(i+x>n)
                break;

            int taken = suffix[i]-suffix[i+x];

            int opponent = solve(i+x,max(M,x));

            int total = suffix[i];

            ans=max(ans,total-opponent);
        }

        return dp[i][M]=ans;
    }


    int stoneGameII(vector<int>& piles)
    {
        n=piles.size();

        suffix.resize(n+1);

        for(int i=n-1;i>=0;i--)
            suffix[i]=suffix[i+1]+piles[i];


        dp.assign(n,vector<int>(n+1,-1));

        return solve(0,1);
    }
};