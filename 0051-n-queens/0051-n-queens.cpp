class Solution {
public:
    void sol(int n, int i,vector<string>&curr, vector<vector<string>>&ans,vector<int>col){
        //base case
        if(i==n){
            ans.push_back(curr);
            return;
        }
      
          //check previous
        for(int j=0;j<n;j++){
            bool safe = true;
            for(int k=0;k<i;k++){
                if(j==col[k] || abs(i-k) == abs(j-col[k])){
                    safe = false;
                    break;
                }
        }
        //place queen
        if(safe){
        curr[i][j] = 'Q';
        col[i] = j;
        sol(n,i+1,curr,ans,col);
        //undo
        curr[i][j]='.';
        }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>curr(n,string(n,'.'));
        vector<vector<string>>ans;
        vector<int> col(n);
        sol(n,0,curr,ans,col);
        return ans;
    }
};