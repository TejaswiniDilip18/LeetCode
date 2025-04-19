class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxIdx < i) return false;
            
            int jump = i + nums[i];
            maxIdx = max(maxIdx, jump);
            
            if(maxIdx >= nums.size()-1) return true;
        }
        return false;
    }
};