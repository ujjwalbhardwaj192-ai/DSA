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
    void sol(TreeNode* root,map<int,int>&mpp,queue<TreeNode*>&q){
         int row=0;
        while(!q.empty()){
            int qs=q.size();
            for(int i=0;i<qs;i++){
                TreeNode* front = q.front();
                q.pop();
                mpp[row] = front->val;

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            row++;
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
         vector<int>ans;
         if(root ==NULL) return ans;
        map<int,int>mpp;
        q.push(root);
        sol(root,mpp,q);

        for(auto &it:mpp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};