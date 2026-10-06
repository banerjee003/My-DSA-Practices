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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }

        int level = 0;
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        vector<int>temp;

        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root == NULL){
                if(level % 2 != 0){
                    reverse(temp.begin(), temp.end());
                }

                ans.push_back(temp);
                temp.clear();
                if(q.empty()){
                    break;
                }
                level++;
                q.push(NULL);
            }
            else{
                temp.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }
        return ans;
    }
};
