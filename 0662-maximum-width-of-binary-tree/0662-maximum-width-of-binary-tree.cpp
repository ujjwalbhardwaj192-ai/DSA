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
    void sol(TreeNode* root, queue<pair<long long,TreeNode*>>&q,long long &maxwidth){
        while(!q.empty()){
            int qs = q.size();

            long long first = q.front().first;
            long long last = q.back().first;

            maxwidth = max(maxwidth,last-first+1);

            for(int i=0;i<qs;i++){
                TreeNode* front = q.front().second;
                long long n = q.front().first - first;
                q.pop();

                if(front->left){
                    q.push({2*n,front->left});
                }

                if(front->right){
                    q.push({2*n+1,front->right});
                }
            }
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long long,TreeNode*>>q;
        long long maxwidth = 0;

        q.push({0,root});

        sol(root,q,maxwidth);

        return maxwidth;
    }
};