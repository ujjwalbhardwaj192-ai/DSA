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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        vector<vector<int>>ans;
        q.push(root);
         bool rev = false;
        if(root ==NULL) return ans;
        while(!q.empty()){
            vector<int>curr;
            int qs=q.size();
            for(int i=0;i<qs;i++){
            TreeNode* front = q.front();
            q.pop();
            curr.push_back(front->val);
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            }
             if(rev){
                reverse(curr.begin(), curr.end());
            }

            ans.push_back(curr);
            rev = !rev;
        }
        return ans;
    }
};