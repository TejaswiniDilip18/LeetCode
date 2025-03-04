class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int sizeNums = nums.size();
        for(int i=0; i<sizeNums; i++){
            if(i>0 && nums[i-1]==nums[i]) continue;

            int j = i+1;
            int k = sizeNums - 1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[k-1]==nums[k]) k--;
                    while(j<k && nums[j+1]==nums[j]) j++;
                    k--;
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }            
            }
        }
        return result;
    }
};