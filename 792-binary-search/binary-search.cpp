class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int first = 0;
        int last = size-1;

        while(first <= last){
            int mid = first + (last - first)/2;
            
            if(target == nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                last = mid - 1;
            }
            else{
                first = mid + 1;
            }
        }

        return -1;
    }
};