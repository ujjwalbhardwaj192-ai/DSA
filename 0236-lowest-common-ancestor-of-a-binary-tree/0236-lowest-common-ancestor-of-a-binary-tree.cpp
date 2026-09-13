/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void route(TreeNode* root, TreeNode* p,vector<TreeNode*>&curr,bool & check,vector<TreeNode*>&ans){
        if(root==NULL) return;
        curr.push_back(root);
        if(root==p && check == false){
            ans = curr;
            check =true;
            return;
        }
        route(root->left,p,curr,check,ans);
        if(check==true)return;

        route(root->right,p,curr,check,ans);
      if(check==true)return;
        curr.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*>curr;
        bool check=false;
        vector<TreeNode*>a1;
        vector<TreeNode*>ans;
        vector<TreeNode*>a2;
        route(root,p,curr,check,ans);
        a1= ans;
        ans.clear();
        curr.clear();
        check =false;
        TreeNode * c= NULL;
        route(root,q,curr,check,ans);
        a2= ans;
        int a=0;
        int b=0;
        while(a<a1.size() && b<a2.size()){
            if(a1[a] == a2[b]){
                c = a1[a];
                a++;
                b++;
            }
            else {break;}
        }
    return c;
    }
};