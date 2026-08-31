class Solution {
public:
    void sol(int k, int n, vector<int>&curr, vector<vector<int>>&ans,int i,int sum ){
        if(curr.size() == k && sum == n){
            ans.push_back(curr);
            return;
        }
        if (i > 9 || curr.size() >= k || sum > n) {
            return;
        }
        //take
        if(sum+i <= n){
            curr.push_back(i);
            sol(k,n,curr,ans,i+1,sum+i);
            curr.pop_back();
        }
        // not take
        sol(k,n,curr,ans,i+1,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        vector<vector<int>>ans;
        sol(k,n,curr,ans,1,0);
        return ans;
    }
};