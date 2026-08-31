class Solution {
public:
    void sol(vector<int>&nums,vector<vector<int>>&ans, vector<int>&curr,int i){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        //take
        curr.push_back(nums[i]);
        sol(nums,ans,curr,i+1);
        curr.pop_back();
        //not take
        sol(nums,ans,curr,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>ans;
        sol(nums,ans,curr,0);
        return ans;
    }
};