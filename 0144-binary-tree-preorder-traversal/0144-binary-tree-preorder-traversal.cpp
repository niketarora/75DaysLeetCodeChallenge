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
    void preorder(TreeNode* root, vector<int> &ans) {
        if (root == NULL) return;
        ans.push_back(root->val); 
        preorder(root->left, ans);     
        preorder(root->right, ans);  
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // METHOD-1 USING RECURSION
        // vector<int> ans;
        // preorder(root, ans);
        // return ans;

        // METHOD-2 ITERATIVE METHOD
        stack<TreeNode*> st;
        vector<int> ans;
        if(root)  st.push(root);
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return ans;
    }
};