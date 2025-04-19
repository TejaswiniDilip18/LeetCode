class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int& n: nums){
            currSum += n;
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum=0;
        }
        return maxSum;
    }
};