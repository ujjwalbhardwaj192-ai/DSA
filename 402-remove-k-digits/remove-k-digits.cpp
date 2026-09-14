class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>s;
        s.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(!s.empty() && s.top()>num[i] && k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() > 1 && ans[0] == '0') {
            ans.erase(ans.begin());
        }
        if(ans == "") return "0";
        return ans;
    }
};