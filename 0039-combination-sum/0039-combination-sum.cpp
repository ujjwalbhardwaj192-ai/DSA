class Solution {
public:
    void helper(vector<int>& candidates, int index, int target,vector<vector<int>>&ans,vector<int>&curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(index ==candidates.size() || target<0){
            return;
        }
        //take
       
        curr.push_back(candidates[index]);
        helper(candidates,index, target - candidates[index],ans,curr);
        //backtrack
        curr.pop_back();
        //not take
        helper(candidates,index+1,target,ans,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(candidates,0,target,ans,curr);
        return ans;
    }
};