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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode *>s;
        if(root == NULL) return ans;
        TreeNode* curr = root;
        TreeNode *lastVisited = NULL;
        while(curr != NULL || !s.empty()){
            while(curr!= NULL){
                s.push(curr);
                curr = curr->left;
            }
            TreeNode* top = s.top();
            if(top->right != NULL && lastVisited != top->right){
                curr = top->right;
            }
            else{
                ans.push_back(top->val);
                lastVisited = top;
                s.pop();
            }
        }
        return ans;
    }
};