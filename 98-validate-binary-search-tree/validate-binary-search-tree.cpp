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
    bool isValidBST(TreeNode* root) {
        if (root==NULL) return true;
      
        queue<tuple<TreeNode*,long long,long long>>q;
        q.push({root,LLONG_MIN,LLONG_MAX});
        while(!q.empty()){
            int qs= q.size();
            for(int i=0;i<qs;i++){
                auto [front,mini,maxi] = q.front();
                q.pop();
                if(front->val>=maxi || front->val<=mini) return false;
                if(front->left != NULL){
                    q.push({front->left,mini,front->val});
                }
                
                if(front->right!=NULL){
                    q.push({front->right,front->val,maxi});
                }
            }
        }
        
        return true;
    }
};