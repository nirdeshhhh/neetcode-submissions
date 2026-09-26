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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(p->val == root->val || q->val == root->val) return root;

        TreeNode* leftnode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightnode = lowestCommonAncestor(root->right, p, q);

        if(leftnode != NULL && rightnode != NULL){
            return root;
        }

        if(leftnode != NULL) return leftnode;

        return rightnode;

    }
};
