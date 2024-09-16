class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = INT_MAX;
        int sum = 0;
        int start = 0;
        for(int end =0; end < nums.size(); end++){
            sum += nums[end];

            while(sum >= target){
                min_length = min(min_length, end-start+1);
                sum -= nums[start];
                start ++;
            }
        }

        return min_length == INT_MAX ? 0 : min_length;
    }
};