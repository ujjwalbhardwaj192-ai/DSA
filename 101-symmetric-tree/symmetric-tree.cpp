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
    void  sol(TreeNode* n1, TreeNode* n2,bool &check){
        if(n1==NULL && n2==NULL && check == true){
            check=true;
            return;
        }
        if(n1==NULL ||n2==NULL){
            check = false;
            return;
        }
        if(n1->val != n2->val){
            check = false;
        }
        sol(n1->left,n2->right,check);
        sol(n1->right,n2->left,check);

    }
    bool isSymmetric(TreeNode* root) {
        bool check = true;
        
         sol(root->left,root->right,check);
         return check;

    }
};