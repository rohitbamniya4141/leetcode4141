/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(root == nullptr) return 0;
        //pick
        if(dp.find(root) != dp.end()){
            return dp[root];
        }
        int c1 = root->val;
        if(root->left){
            c1 += (solve(root->left->left, dp) + solve(root->left->right, dp));
        }
        if(root->right){
            c1 += (solve(root->right->left, dp) + solve(root->right->right, dp));
        }

        // dont pick

        int c2 = solve(root->left, dp) + solve(root->right, dp);

        return dp[root] = max(c1,c2);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int>dp;
        return solve(root, dp);
    }
};