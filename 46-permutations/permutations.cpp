class Solution {
private:
    void findPermutations(vector<int>& nums, vector<vector<int>>& result, int start, int& n){
        if(start == n){
            result.push_back(nums);
            return;
        }

        for(size_t i=start; i<n; i++){
            swap(nums[start], nums[i]);
            findPermutations(nums, result, start+1, n);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        int start = 0;
        findPermutations(nums, result, start, n);

        return result;
    }
};