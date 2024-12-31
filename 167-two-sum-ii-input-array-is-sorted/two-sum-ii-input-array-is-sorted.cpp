class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int left = 0;
        int right = size-1;

        

        while(right > left){
            int sum = numbers[left] + numbers[right];
            // cout<<sum<<endl;

            if(target==sum){
                return {left+1, right+1};
            }
            else if(target < sum){
                right--;
            }
            else{
                left++;
            }
        }
        return {-1,-1};
    }
};