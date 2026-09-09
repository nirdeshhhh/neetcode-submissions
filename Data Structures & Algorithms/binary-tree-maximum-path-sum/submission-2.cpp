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

    int mx = INT_MIN;

    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int one_of_them = max(max(l,r) + root->val, root->val);
        int found_below = max(one_of_them, l + r + root->val);
        mx = max(mx, found_below);

        return one_of_them;
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return mx;
    }
};
