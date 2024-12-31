class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // if(nums.size()==1){
        //     return 0;
        // }

        std::unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; 

        int prefix_sum = 0;
        int max_length = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                prefix_sum -= 1;
            }
            else{
                prefix_sum += 1;
            }
            // check if prefix sum was encountered before
            if(prefix_map.find(prefix_sum) != prefix_map.end()){
                int len = i - prefix_map[prefix_sum];
                max_length = max(max_length, len);
            }
            else{
                prefix_map[prefix_sum] = i;
            }
        }        

        return max_length;
    }
};