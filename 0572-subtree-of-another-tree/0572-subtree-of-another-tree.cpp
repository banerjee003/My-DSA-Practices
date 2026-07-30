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
    bool isIdentical(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL and root2 == NULL){
            return true;
        }
        else if(root1 == NULL or root2 == NULL){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }

        return isIdentical(root1->left, root2->left) and isIdentical(root1->right, root2->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot == NULL){
            return true;
        }
        else if(root == NULL or subRoot == NULL){
            return false;
        }

        if((root->val == subRoot->val) and isIdentical(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
