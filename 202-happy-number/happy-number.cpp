class Solution {
public:
    int squareSum(int n){
        int sum = 0;

        while(n>0){
            int digit = n%10;
            sum += (digit*digit);
            n = n/10;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int, int> visit_map;

        // while we haven't visited the sum already
        while(!(visit_map.find(n) != visit_map.end())){

            visit_map[n] = true;

            n = squareSum(n);
            if(n == 1) return true;  
        }
        return false;
    }
};