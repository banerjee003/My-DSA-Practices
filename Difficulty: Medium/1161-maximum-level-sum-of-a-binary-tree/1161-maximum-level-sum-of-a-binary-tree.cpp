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
        int sum = 0, level = 0, maxLevel=0, maxSum = INT_MIN;
        queue<TreeNode*>q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root == NULL){
                level++;
                if(sum > maxSum){
                    maxLevel = level;
                    maxSum = sum;
                }

                if(q.empty()){
                    break;
                }
                sum = 0;
                q.push(NULL);
            }
            else{
                sum += root->val;
                if(root->left){           // if the child are not null only then push
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
        }
        return maxLevel;
    }
};
