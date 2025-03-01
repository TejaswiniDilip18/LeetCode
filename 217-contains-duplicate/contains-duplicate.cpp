class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // map<int,int> mp;
        // for(int num: nums){
        //     if(mp.find(num) != mp.end()) return true;
        //     else mp[num]++;
        // }
        // return false;

        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};