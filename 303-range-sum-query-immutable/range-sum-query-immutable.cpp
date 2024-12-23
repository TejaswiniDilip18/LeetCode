class NumArray {
public:
    vector<int> numsArr;
    NumArray(vector<int>& nums) {
        numsArr = nums;
    }

    // vector<int> getPrefixSum(vector<int>& numsArr){
    //     int sum = 0;
    //     vector<int> prefixSum(numsArr.size());
    //     for(int i=0; i<numsArr.size(); i++){
    //         prefixSum[i] = sum + numsArr[i];
    //     }
    //     return prefixSum;
    // }
    
    int sumRange(int left, int right) {
        int sum = 0;
        vector<int> prefixSum(numsArr.size(),0);
        prefixSum[0] = numsArr[0];
        
        for(int i=1; i<numsArr.size(); i++){
            prefixSum[i] = prefixSum[i-1] + numsArr[i];
        }
        return (prefixSum[right]-prefixSum[left]+numsArr[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */