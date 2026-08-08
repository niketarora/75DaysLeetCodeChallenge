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
    void solve(TreeNode* root, int curr, int targetSum, vector<int> ds, vector<vector<int>> &ans){
        if(root == NULL){
            if(ds.size() != 0){
                ds.pop_back();
            }
            return;
        }

        curr += root->val;
        ds.push_back(root->val);
        
        if(root->right == NULL && root->left == NULL){
            if(targetSum == curr)   ans.push_back(ds);
            else{
                ds.pop_back();
            }
            return;
        }

        solve(root->left, curr, targetSum, ds, ans); 
        solve(root->right, curr, targetSum, ds, ans); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int curr = 0;
        vector<vector<int>> ans;
        vector<int>  ds;
        solve(root, curr, targetSum, ds, ans);
        return ans;
    } 
};