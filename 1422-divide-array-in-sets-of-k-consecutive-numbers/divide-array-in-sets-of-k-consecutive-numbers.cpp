class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0) return false;

        sort(nums.begin(), nums.end());

        unordered_map<int,int> count;
        for(int& num: nums){
            count[num]++;
        }

        for(int num: nums){
            if(count[num] > 0){ 
                for(int i=0; i<k; i++){
                    if(count.find(num+i) == count.end() || count[num+i] <= 0) return false;
                    else count[num+i]--;
                }
            }
        }
        return true;
    }
};