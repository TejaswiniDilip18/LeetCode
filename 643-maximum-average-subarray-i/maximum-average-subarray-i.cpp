class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = -DBL_MAX;
        double currSum = 0.0;
        int left = 0;
        
        for(int right=0; right<nums.size(); right++){
            currSum += nums[right];

            if((right - left + 1) == k){
                maxSum = max(maxSum, currSum);
                currSum = currSum - nums[left];
                left++;
            }
        }
        return maxSum/(double)k;
    }
};