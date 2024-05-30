class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while(r>l){
            int sum = numbers[r] + numbers[l];

            if(sum == target) return {l+1, r+1};
            else if(sum > target) r--;
            else l++;
        }
        return {-1, -1};
    }
};