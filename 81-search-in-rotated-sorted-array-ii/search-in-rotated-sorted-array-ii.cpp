class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = (right+left)/2;
           
            if(nums[mid]==target) return true;

            else if(nums[mid]==nums[left] && nums[mid]==nums[right]){
                left++;
                right--;
            }

            else if(nums[mid] <= nums[right]){
                // right half is sorted
                if(target > nums[mid] && target <= nums[right]){
                    left = mid+1;
                }
                else right = mid-1;
            }
            else{
                // left half is sorted
                if(target < nums[mid] && target >= nums[left]){
                    right = mid-1;
                }
                else left = mid+1;
            }
        }
        return false;
    }
};