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
    void sol(TreeNode* root ,vector<string>&ans,string &curr,int &count){
        if(root==NULL){
            return;
        } 
        int s=0;
        if(curr.length() ==0){
            s=curr.length();
            curr.append(to_string(root->val));
        }
        else{
            s = curr.length();
            curr+="->";
            curr.append(to_string(root->val));
        }  
        if(root->left == NULL && root->right == NULL){
            ans.push_back(curr);
            curr.erase(s); 
            return;
        }
        count =0;
        sol(root->left,ans,curr,count);
        sol(root->right,ans,curr,count);
        curr.erase(s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string curr = "";
        if(root==NULL){
            return ans;
        }
        int count =0;
        sol(root,ans,curr,count);
        return ans;

    }
};