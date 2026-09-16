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
    void addParent(TreeNode* root,map<TreeNode*,TreeNode*>&mpp){
        if(root==NULL) return;
        if(root->left){
            mpp[root->left]=root;
        }
        if(root->right){
            mpp[root->right] = root;
        }
        addParent(root->left,mpp);
        addParent(root->right,mpp);
    }
    void route(TreeNode* target,int d,int k,vector<int>&ans,TreeNode* prev,map<TreeNode*,TreeNode*>&mpp){
         if(target == NULL){
            return;
        }
        if(d==k){
            ans.push_back(target->val);
            return;
        }
        //left
        if(target->left!=prev){
        route(target->left,d+1,k,ans,target,mpp);
        }
        //rught
        if(target->right != prev){
        route(target->right,d+1,k,ans,target,mpp);
        }
        //parent
        if(mpp[target] != prev){
        route(mpp[target],d+1,k,ans,target,mpp);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==target && root == NULL) return ans;
        map<TreeNode*,TreeNode*>mpp;
        addParent(root,mpp);
        int d=0;
        TreeNode* prev =NULL;
        route(target,d,k,ans,prev,mpp);
        return ans;
    }
};