class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX;
        int closeSum = INT_MAX;

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = min(abs(target-sum), minDiff);

                if(minDiff > diff){
                    closeSum = sum;
                    minDiff = diff;
                }

                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    // to avoid considering duplicate values for j and k
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }        

        return closeSum;
    }
};