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
    int sol(TreeNode* root,int &maxv){
        if(root==NULL)return 0;
        int left = max(0,sol(root->left,maxv));
        int right = max(0,sol(root->right,maxv));
        maxv = max(maxv,left+right+root->val);
        return root->val+ max(left,right);

    }
    int maxPathSum(TreeNode* root) {
        int maxv= INT_MIN;
        sol(root,maxv);
        return maxv;
    }
};