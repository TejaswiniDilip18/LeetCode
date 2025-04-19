class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int& n: nums){
            if(currSum < 0) currSum=0;
            currSum += n;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};