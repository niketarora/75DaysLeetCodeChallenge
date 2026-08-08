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
    bool solve(TreeNode* root, int curr, int targetSum){
        if(root == NULL)    return false;

        curr += root->val;
        
        if(root->right == NULL && root->left == NULL){
            if(targetSum == curr)   return true;
            else    return false;
        }

        bool left = solve(root->left, curr, targetSum); 
        bool right = solve(root->right, curr, targetSum); 
        
        return left || right;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int curr = 0;
        bool res = solve(root, curr, targetSum);
        return res;
    }
};