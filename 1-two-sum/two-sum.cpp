class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                result.push_back(i);
                result.push_back(mp[nums[i]]);
                return result;
            }
            else mp[target - nums[i]] = i;
        }
        return result;
    }
};