class Solution {
public:
    bool checkpali(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
                break;
            }
            i++;
            j--;
        }
        return true;
    }
    void sol(string &s,vector<string>&curr, vector<vector<string>>&ans,int i){
        if(i==s.size()){
            ans.push_back(curr);
            return;
        }
        
        
        for(int j=i;j<s.size();j++){
            if(checkpali(s,i,j)){
                curr.push_back(s.substr(i,j-i+1));
                sol(s,curr,ans,j+1);
                curr.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        vector<vector<string>>ans;
        sol(s,curr,ans,0);
        return ans;
    }
};