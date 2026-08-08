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
    int solve(TreeNode* root, int curr, int &total){
        if(root == NULL)    return 0;
        curr = (curr*10) + root->val;
        if(root->left == NULL && root->right == NULL){
            total += curr;
            curr /= 10;
            return total;
        }

        int left = solve(root->left, curr, total);
        int right = solve(root->right, curr, total);

        return total;
    }
    int sumNumbers(TreeNode* root) {
        int curr = 0;
        int total = 0;
        int res = solve(root, curr, total);
        return res;
    }
};