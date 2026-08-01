/*
Problem: 1. Two Sum
Platform: LeetCode
Topic: Arrays, Hash Map

Approach:
- Traverse the array once.
- Store each number and its index in a hash map.
- For every element, check whether (target - nums[i]) already exists.
- If it exists, return the two indices.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;

        for(int i = 0; i < nums.size(); i++) {

            if(mpp.find(target - nums[i]) == mpp.end()) {
                mpp[nums[i]] = i;
            }
            else {
                return {mpp[target - nums[i]], i};
            }
        }

        return {};
    }
};