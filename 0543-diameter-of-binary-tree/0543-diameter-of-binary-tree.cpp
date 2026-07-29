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
    pair<int,int> diameter(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pair<int, int>left = diameter(root->left);
        pair<int, int>right = diameter(root->right);

        int currDiam = left.second + right.second;
        int maxDiam = max(currDiam, max(left.first, right.first));
        int maxHt = 1 + max(left.second, right.second);

        return {maxDiam, maxHt};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};
