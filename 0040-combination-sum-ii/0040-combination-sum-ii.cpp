class Solution {
public:
    void sol(vector<int>&candidates, int target, int sum,int i,vector<vector<int>>&ans,vector<int>&curr){
        //base case
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(i == candidates.size() || sum>target){
            return;
        }
        //take candidate
        if(sum+candidates[i]<=target){
            curr.push_back(candidates[i]);
            sol(candidates,target,sum+candidates[i],i+1,ans,curr);
            curr.pop_back();
        }
      
        while(i+1<candidates.size() && candidates[i] == candidates[i+1] ){
            i+=1;
        
        }
        sol(candidates,target,sum,i+1,ans,curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        vector<vector<int>>ans;
        sol(candidates,target,0,0,ans,curr);
        return ans;
    }
};