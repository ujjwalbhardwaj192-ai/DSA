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
    
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        stack<TreeNode*>s;
        s.push(root);
        int count=1;
        while(!s.empty()){
            TreeNode* top = s.top();
            while(top->left!=NULL){
                s.push(top->left);
                TreeNode* temp = top;
                top = top->left;
                temp->left = NULL;
            }
            s.pop();
            if(count == k){
                return top->val;
            }
            else{
                count++;
            }
            if(top->right!=NULL){
            s.push(top->right);
            }
        }
        return 0;  
    }
};