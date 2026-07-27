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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr)
            return -1;

        vector<long long>ans;
        queue<TreeNode*>q;
        long long sum = 0;
        
        q.push(root);
        q.push(NULL);   
        while(!q.empty()){
            root = q.front();
            q.pop();

            if(root == NULL){
                ans.push_back(sum);
                if(q.empty()){
                    break;
                }
                sum = 0;
                q.push(NULL);
            }
            else{
                sum += root->val;
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
        }

        long long n = ans.size();
        if(k > n) return -1;

        sort(ans.begin(), ans.end(), [](const long long &a, const long long &b){
            return a > b;
        });

        return ans[k-1];
    }
};
