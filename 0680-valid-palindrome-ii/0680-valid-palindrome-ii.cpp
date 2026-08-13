class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j= s.length()-1;
        while(i<j){
            while(s[i] == s[j] && i<j){
                i++;
                j--;
            }
            if (i >= j){
                 return true;
            }
            int temp1 = i+1;
            int temp2 = j-1;
           int a = temp1;
           int b = j;
           bool first = true;
           while(a<b){
            if(s[a] != s[b]){
                first =  false;
                break;
            }
            a++;
            b--;
           }
           bool second = true;
            a = i;
            b = temp2;
            while(a<b){
            if(s[a] != s[b]){
                second =  false;
                break;
            }
            a++;
            b--;
           }
            return first || second;
        }
        return true;
    }
};