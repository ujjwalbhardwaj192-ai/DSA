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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *>s;
        vector<int>ans;
        if(root == NULL){
            return ans;
        }
        s.push(root);
        while(!s.empty()){
            TreeNode* front = s.top();
            while(front->left != NULL){
               
                s.push(front->left);
                TreeNode * temp = front;
                front = front->left;
             
                temp->left = NULL;
            }
            s.pop();
            ans.push_back(front->val);
            if(front->right != NULL){
                s.push(front->right);
            }
        }
        return ans;
    }
};