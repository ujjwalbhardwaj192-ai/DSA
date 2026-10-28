class Solution {
public:
int helper(int n,vector<int>&a){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(a[n] !=-1){
        return a[n];
    }
    a[n] = helper(n-1,a)+ helper(n-2,a);
    return a[n];

}
    int climbStairs(int n) {
        vector<int>a(n+1,-1);
        return helper(n,a);
    }
};