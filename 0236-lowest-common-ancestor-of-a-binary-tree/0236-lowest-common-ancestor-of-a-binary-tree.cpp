/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rootToNode(TreeNode* root, TreeNode* n, vector<TreeNode*>&path){
        if(root == NULL){
            return false;
        }
        path.push_back(root);

        if(root->val == n->val){
            return true;
        }

        bool isLeft = rootToNode(root->left, n, path);
        bool isRight = rootToNode(root->right, n, path);

        if(isLeft || isRight){
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;

        rootToNode(root, p, path1);
        rootToNode(root, q, path2);

        TreeNode* lca = NULL;

        for(int i = 0; i < min(path1.size(), path2.size()); i++){
            if(path1[i]->val != path2[i]->val){
                return lca;
            }
            lca = path1[i];
        }
        return lca;
    }
};
