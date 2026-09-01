class Solution {
public:
    void sol(vector<string>&vec,string digits,string curr,vector<string>&ans,int i){
        
        if(curr.size() == digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters =vec[digits[i] - '0'];
        for(int j=0;j<letters.size();j++){
            curr.push_back(letters[j]);
            sol(vec,digits,curr,ans,i+1);
            curr.pop_back();
        }

        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>vec(10);
        int i=0;
        vec[0] ="";
        vec[1]="";
        vec[2]="abc";
        vec[3]="def";
        vec[4]="ghi";
        vec[5]="jkl";
        vec[6]="mno";
        vec[7]="pqrs";
        vec[8]="tuv";
        vec[9]="wxyz";
        vector<string>ans;
        sol(vec,digits,"",ans,0);
        return ans;

    }
};