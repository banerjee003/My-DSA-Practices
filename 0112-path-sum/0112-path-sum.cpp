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
    bool check(TreeNode* root, int targetSum){
        if(root == NULL){
            return false;
        }

        if(root->left == NULL && root->right == NULL){
            return targetSum == root->val;
        }

        targetSum -= root->val;

        return check(root->left, targetSum) || check(root->right, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum);
    }
};
