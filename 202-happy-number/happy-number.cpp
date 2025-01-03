class Solution {
public:
    int squaredSum(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            sum += (digit*digit);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int,int> map;

        while(map.find(n)==map.end()){
            int new_sum = squaredSum(n);
            map[n] = new_sum;

            if(new_sum==1) return true;

            n = new_sum;
        }   
        return false;             
    }
};