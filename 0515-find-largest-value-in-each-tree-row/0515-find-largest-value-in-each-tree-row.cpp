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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)    return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            TreeNode* temp = NULL;
            int currMax = INT_MIN;
            while(n--){
                temp = q.front();
                currMax = max(currMax, temp->val);
                if(temp->left != NULL)  q.push(temp->left);
                if(temp->right != NULL)   q.push(temp->right);
                q.pop();
            }
            ans.push_back(currMax);
        }
        return ans;
    }
};