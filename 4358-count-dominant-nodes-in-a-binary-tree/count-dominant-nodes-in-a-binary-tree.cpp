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
    int solve(TreeNode* root, int &ans){
        if(root == nullptr) return INT_MIN;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        int curr = root->val;

        int maxi = max(curr, max(left,right));

        if(curr == maxi) ans++;

        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        int m = solve(root, ans);
        return ans;
    }
};