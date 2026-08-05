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
    int maxdiff = -1;
    void findMax(TreeNode* root, TreeNode* child){
        if(child == NULL)    return;
        maxdiff = max(maxdiff, abs(root->val - child->val));

        findMax(root, child->left);
        findMax(root, child->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)    return 0;

        findMax(root, root->left);
        findMax(root, root->right);

        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);

        return maxdiff;
    }
};