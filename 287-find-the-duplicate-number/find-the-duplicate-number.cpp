class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);

        slow = nums[0];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;

        // using unordered map, but uses extra space
        /* unordered_map<int, int> map;

        for(int i=0; i<nums.size();i++){
            if(map.find(nums[i]) != map.end()){
                return nums[i];
            }
            else map[nums[i]] = i;
        }
   
        return -1;  
        */
    }
};