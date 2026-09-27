class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
         long long mod =1e9 +7;
        vector<pair<int,int>>a;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<speed.size();i++){
            a.push_back({efficiency[i], speed[i]});
        }
        sort(a.begin(),a.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });
        long long max_sum=0;
        long long sum=0;
        for(int i=0;i<a.size();i++){
        sum+=a[i].second;
         q.push(a[i].second);
        if(q.size()>k){
            sum-=q.top();
            q.pop();
        }
           
        max_sum = max(max_sum,sum*a[i].first);

        }
       
        return max_sum%mod;
    }
};