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
    int s;
    TreeNode * sol(vector<int>& inorder, vector<int>& postorder,map<int,int>&mpp, int left ,int right){
        if(left>right){
            return NULL;
        }
        int curr = postorder[s--];
        TreeNode * root= new TreeNode(curr);
        int mid = mpp[curr];
        root->right = sol(inorder,postorder,mpp,mid+1,right);
        root->left = sol(inorder,postorder,mpp,left,mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        s = postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        return sol(inorder,postorder,mpp,0,inorder.size()-1);
    }
};