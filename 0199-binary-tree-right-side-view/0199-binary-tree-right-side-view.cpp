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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }

        int level = 0;
        queue<TreeNode*>q;  
        map<int, int>m;      // Storing {level, node_value}

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode == NULL){
                level++;
                if(q.empty()){
                    break;
                }
                q.push(NULL);
            }
            else{
                m[level] = currNode->val;
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
        }

        vector<int>ans;

        for(auto i : m){
            ans.push_back(i.second);
        }

        return ans;
    }
};
