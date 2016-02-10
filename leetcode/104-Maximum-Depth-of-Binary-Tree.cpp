/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 1;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return depth + (leftDepth >= rightDepth ? leftDepth : rightDepth);
    }
};
