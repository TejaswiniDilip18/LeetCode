class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int maxCount = 0;

        for(int num: us){
            if(!us.count(num-1)){
                int n = num;
                int count = 1;

                while(us.count(n+1)){
                    n++;
                    count++;
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};