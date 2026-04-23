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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            // Traverse to the leftmost node
            while (root) {
                stk.push(root);
                root = root->left;
            }
            // Process the current node
            root = stk.top();
            stk.pop();
            
            if (--k == 0) return root->val; // Found the kth smallest
            
            // Move to the right subtree
            root = root->right;
        }
        return -1; // Should not reach here for valid k
    }
};
