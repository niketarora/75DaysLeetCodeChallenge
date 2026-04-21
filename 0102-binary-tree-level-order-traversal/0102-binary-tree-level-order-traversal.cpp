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
    void nthLevel(TreeNode* root, int level, int count, vector<int> &v) {
        if (root == NULL) return;
        if(level == count){
            v.push_back(root->val);
            return;
        }
        nthLevel(root->left, level, count+1, v);     
        nthLevel(root->right, level, count+1, v);  
    }
    int levels(TreeNode* root){
        if(root == NULL)   return 0 ;
        return 1 + max(levels(root->left), levels(root->right)); 
    }
    void eachLevel(TreeNode* root, vector<vector<int>> &ans){
        int n = levels(root);
        for(int i=1; i<=n; i++){
            vector<int> v;
            nthLevel(root, i, 1, v);
            ans.push_back(v);
        }
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        eachLevel(root, ans);
        return ans;
    }
};