class Solution {
public:
    void sol(vector<int>& candidate, int target,int i,int sum,vector<int>&curr,vector<vector<int>>&ans ){
        //base case
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(i == candidate.size() || sum>target){
            return;
        }
        //take element
       
            
            if(sum+candidate[i]<=target){
                curr.push_back(candidate[i]);
                sol(candidate,target,i,sum+candidate[i],curr,ans);
                curr.pop_back();
            }
        
        
            sol(candidate,target,i+1,sum,curr,ans);

       
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans ;
   
        sol(candidates,target,0,0,curr,ans);
        return ans;
    }
};