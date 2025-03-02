class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int product = 1;
        int zeroCount = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroCount++;
                continue;
            };
            product = product * nums[i];
        }

        if(zeroCount > 1) return result;

        for(int i=0; i<nums.size(); i++){
            if(zeroCount == 0) result[i] = product / nums[i];
            else 
                if(nums[i] == 0) result[i] = product;
        }
        return result;
    }
};