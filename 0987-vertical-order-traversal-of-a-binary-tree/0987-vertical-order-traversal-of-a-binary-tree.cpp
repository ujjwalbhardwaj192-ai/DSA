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

    vector<tuple<int,int,int>> v;

    void solve(TreeNode* root, int row, int col){

        if(root == NULL) return;

        v.push_back({col, row, root->val});

        solve(root->left, row + 1, col - 1);
        solve(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        solve(root, 0, 0);

        sort(v.begin(), v.end());

        vector<vector<int>> ans;

        int col = INT_MIN;

        for(auto x : v){

            if(get<0>(x) != col){
                ans.push_back({});
                col = get<0>(x);
            }

            ans.back().push_back(get<2>(x));
        }

        return ans;
    }
};