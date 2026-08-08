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
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 1;
        int currLevel = 1;
        int maxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        maxSum = root->val;
        while(!q.empty()) {

            int n = q.size();
            int currSum = 0;
            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                currSum += temp->val;

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
            
            if(currSum > maxSum){
                maxSum = max(currSum , maxSum);
                maxLevel = currLevel;
            }
            currLevel++;
        }
        return maxLevel;
    }
};