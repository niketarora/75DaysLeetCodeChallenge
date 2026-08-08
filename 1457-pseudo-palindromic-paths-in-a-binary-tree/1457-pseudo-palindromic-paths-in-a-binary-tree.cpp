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
    bool isPalindrom(vector<int>& v){
        int isOdd = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i]%2)  isOdd++;
        }

        if(isOdd > 1)   return false;
        else return true;
    }
    int solve(TreeNode* root, vector<int>& v){
        if(root == NULL){
            return 0;
        }
        v[root->val]++;

        if(root->left == NULL && root->right == NULL){
            int ans = isPalindrom(v);
            v[root->val]--;

            return ans;
        }

        int left = solve(root->left, v);
        int right = solve(root->right, v);

        v[root->val]--;

        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10, 0);
        int res = solve(root, v);
        return res;
    }
};