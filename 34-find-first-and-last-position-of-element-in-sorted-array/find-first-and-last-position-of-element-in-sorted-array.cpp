class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        int l=0;
        int r=nums.size()-1;
        int x=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(target<nums[mid]){
                r=mid-1;
            }
            else if(target>nums[mid]){
                l=mid+1;
            }
            else{
                 x=mid;
                 break;
            }
           
        }
        if(x!=-1){
            int i= x;
            int j = x;
            if(x != -1){

    int i = x;
    int j = x;

  
    int l = 0;
    int r = x;

    while(l <= r){
        int mid = l + (r-l)/2;

        if(nums[mid] == target){
            i = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    
    l = x;
    r = nums.size()-1;

    while(l <= r){
        int mid = l + (r-l)/2;

        if(nums[mid] == target){
            j = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    ans[0] = i;
    ans[1] = j;
}
        }
        return ans;
    }
};