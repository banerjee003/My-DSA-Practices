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
    bool final = true;

    bool traverse(TreeNode* root, int data){
        if(root == NULL){
            return true;
        }

        traverse(root->left, data);
        traverse(root->right, data);

        if(root->val != data){
            final = false;
        }
        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        int data = root->val;
        traverse(root, data);
        return final;
    }
};
