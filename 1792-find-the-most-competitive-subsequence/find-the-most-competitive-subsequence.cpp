class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>s;
        s.push(nums[0]);
        int removal = nums.size()-k;
        for(int i=1;i<nums.size();i++){
            
            while(!s.empty() && s.top() > nums[i] && removal > 0){
                s.pop();
                removal--;
            }
            s.push(nums[i]);
        }
        while(removal>0){
            s.pop();
            removal--;
        }
         vector<int> ans;

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};