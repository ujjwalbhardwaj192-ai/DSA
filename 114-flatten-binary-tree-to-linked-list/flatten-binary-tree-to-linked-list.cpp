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
    void flatten(TreeNode* root) {
        stack<TreeNode*>s;
        vector<TreeNode*>pre;
        s.push(root);
        if(root== NULL) return;
        while(!s.empty()){
            TreeNode * curr = s.top();
            s.pop();
            pre.push_back(curr);
            if(curr->right!= NULL){
                s.push(curr->right);
            }
            if(curr->left!= NULL){
                s.push(curr->left);
            }
        }
        TreeNode* curr = root;
        for(int i=1;i<pre.size();i++){
            curr->right = pre[i];
            curr->left= NULL;
            curr = curr->right;
        }
        return;
    }
};