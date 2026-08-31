class Solution {
public:
    void sol(vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans,int i){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        //take
        curr.push_back(nums[i]);
        sol(nums,curr,ans,i+1);
        //backtrack
        curr.pop_back();
        //not take but at the same level skip please
        while(i+1<nums.size() && nums[i] == nums[i+1]){
            i=i+1;
        }
        //not take
        sol(nums,curr,ans,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>ans;
        sol(nums,curr,ans,0);
        return ans;
    }
};