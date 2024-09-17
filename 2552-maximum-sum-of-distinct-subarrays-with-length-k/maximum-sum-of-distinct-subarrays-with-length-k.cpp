class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int start = 0;
        long long current_sum = 0, max_sum = 0;
        unordered_set<int> unique_elements;

        for(int end = 0; end < nums.size(); end++){
            // slide window to right if the element already exists
            while(unique_elements.count(nums[end])){
                unique_elements.erase(nums[start]);
                current_sum -= nums[start];
                start++;
            }
            unique_elements.insert(nums[end]);
            current_sum += nums[end];

            // check if subarray length is k
            if(end-start+1 == k){
                max_sum = max(max_sum, current_sum);

                // slide window to right to check next subarray
                unique_elements.erase(nums[start]);
                current_sum -= nums[start];
                start++;
            }
        }
        return max_sum;
    }
};