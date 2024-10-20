class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if(nums.empty()) return -1;

        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = (left + right)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] <= nums[right]){
                if(target > nums[mid] && nums[right] >= target){
                    left = mid + 1;
                }
                else{
                    right = mid -1;
                }
            }
            else{
                if(target < nums[mid] && nums[left] <= target){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};