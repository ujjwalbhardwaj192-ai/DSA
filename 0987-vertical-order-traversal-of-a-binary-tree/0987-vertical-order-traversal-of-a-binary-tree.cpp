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
    void sol(TreeNode* root,
             unordered_map<int, vector<pair<int, int>>>& mpp,
             queue<pair<TreeNode*, int>>& q) {

        int row = 0;

        while (!q.empty()) {

            int qs = q.size();

            for (int i = 0; i < qs; i++) {

                TreeNode* front = q.front().first;
                int col = q.front().second;
                q.pop();

                mpp[col].push_back({row, front->val});

                if (front->left) {
                    q.push({front->left, col - 1});
                }

                if (front->right) {
                    q.push({front->right, col + 1});
                }
            }

            row++;
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if (root == nullptr)
            return {};

        unordered_map<int, vector<pair<int, int>>> mpp;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        sol(root, mpp, q);

        // Get all columns
        vector<int> columns;

        for (auto& it : mpp) {
            columns.push_back(it.first);
        }

        // Sort columns from left to right
        sort(columns.begin(), columns.end());

        vector<vector<int>> ans;

        // Process each column
        for (int col : columns) {

            auto& nodes = mpp[col];

            // Sort by row, then value
            sort(nodes.begin(), nodes.end());

            vector<int> currentColumn;

            for (auto& p : nodes) {
                currentColumn.push_back(p.second);
            }

            ans.push_back(currentColumn);
        }

        return ans;
    }
};