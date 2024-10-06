class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nums_map;

        for(int i=0; i<nums.size(); i++){
            int sol = target - nums[i];

            if(nums_map.find(sol) != nums_map.end()){
                return {nums_map[sol], i};
            }
            else{
                nums_map[nums[i]] = i;
            }
        }
        return {-1, -1};          
    }
};