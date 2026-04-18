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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        // If leaf node, check sum
        if (root->left == NULL && root->right == NULL) {
            return (targetSum == root->val);
        }
        int remaining = targetSum - root->val;

        // Store results in two variables
        bool left = hasPathSum(root->left, remaining);
        bool right = hasPathSum(root->right, remaining);

        // Check both sides
        return left || right;
    }
};