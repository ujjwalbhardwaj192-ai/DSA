class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m  = obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1){
            return 0;
        }

        vector<vector<int>>dp(m,vector<int>(n,0));
        bool check1 = false;
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]==1 || check1 == true){
                dp[0][j] = 0;
                check1 = true;
            }
            else{
                dp[0][j]=1;
            }
        }
        bool check2 = false;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0] == 1 || check2 == true){
                dp[i][0] = 0;
                check2 = true;
            }
            else{
                dp[i][0]= 1;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};