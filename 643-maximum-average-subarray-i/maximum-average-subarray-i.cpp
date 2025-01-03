class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // int left = 0;
        // int right = k-1;
        double curr_sum = 0.0;

        for(int i=0; i<k; i++){
            curr_sum += nums[i];
        }
        
        double max_sum = curr_sum;

        for(int i=0; i<nums.size()-k; i++){
            curr_sum = curr_sum - nums[i] + nums[i+k];
            max_sum = max(max_sum, curr_sum);
        }

        return (max_sum/k);
    }
};