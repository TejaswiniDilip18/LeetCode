class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curr_sum = 0.0;

        for(int i=0; i<k; i++){
            curr_sum += nums[i];
        }
        
        int max_sum = curr_sum;

        for(int i=0; i<nums.size()-k; i++){
            curr_sum = curr_sum - nums[i] + nums[i+k];
            max_sum = max(max_sum, curr_sum);
        }

        return static_cast<double>(max_sum) / k;
    }
};