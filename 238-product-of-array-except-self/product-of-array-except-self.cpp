class Solution {
public:
// Using division operation
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> result(nums.size(), 0);
    //     int product = 1;
    //     int zeroCount = 0;

    //     for(int i=0; i<nums.size(); i++){
    //         if(nums[i] == 0){
    //             zeroCount++;
    //             continue;
    //         };
    //         product = product * nums[i];
    //     }

    //     if(zeroCount > 1) return result;

    //     for(int i=0; i<nums.size(); i++){
    //         if(zeroCount == 0) result[i] = product / nums[i];
    //         else 
    //             if(nums[i] == 0) result[i] = product;
    //     }
    //     return result;
    // }

// without using division operation
    vector<int> productExceptSelf(vector<int>& nums){
        vector<int> result(nums.size(),1);
        
        int prefix = 1;
        for(int i=0; i<nums.size(); i++){
            result[i] = prefix;
            prefix = prefix * nums[i];
        }

        int suffix = 1;
        for(int i= nums.size()-1; i>=0; i--){
            result[i] *= suffix;
            suffix = suffix * nums[i];
        }

        return result;
    }
};