class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int curr_length=1;
        int max_length =1;     
        
        for(int i=1; i<nums.size(); i++){
           if(nums[i] == nums[i-1]) continue; //skip duplicates
           else if(nums[i] == nums[i-1]+1){
            curr_length++;
           }
           else {
                max_length = max(curr_length, max_length);
                curr_length =1;
           }
        }
        max_length = max(curr_length, max_length);
        return max_length;
    }
};