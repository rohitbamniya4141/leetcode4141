class Solution {
public:
    static const int MOD = 1e9 + 7;

    int n;
    int gcdTable[201][201];
    int dp[201][201][201];

    int solve(int idx, int g1, int g2, vector<int>& nums) {

        if (idx == n)
            return (g1 == g2 && g1 != 0);

        int &ans = dp[idx][g1][g2];
        if (ans != -1)
            return ans;

        long long res = 0;

        // Skip
        res += solve(idx + 1, g1, g2, nums);

        // Put in first subsequence
        res += solve(idx + 1,
                     gcdTable[g1][nums[idx]],
                     g2,
                     nums);

        // Put in second subsequence
        res += solve(idx + 1,
                     g1,
                     gcdTable[g2][nums[idx]],
                     nums);

        return ans = res % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {

        n = nums.size();

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i <= 200; i++)
            for (int j = 0; j <= 200; j++)
                gcdTable[i][j] = std::gcd(i, j);

        return solve(0, 0, 0, nums);
    }
};