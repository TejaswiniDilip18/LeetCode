class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplet;
        sort(nums.begin(), nums.end());

        int size = nums.size();

        for(int i=0; i<nums.size(); i++){
            
            //skip duplicates
            if(i>0 && nums[i] == nums[i-1]) continue; 

            //initialize left and right pointers
            int l = i+1;
            int r = size - 1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];

                if(sum == 0){
                    triplet.push_back({nums[i], nums[l] ,nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;

                    l++;
                    r--;
                }
                else if(sum > 0) r--;
                else l++;
            }
        }
        return triplet;
    }
};