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

    // USING TWO-POINTER METHOD
    bool isHappy(int n) {
        int slow = n;
        int fast = squareSum(n);

        while(fast!=1 && slow != fast){
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }

        return fast == 1;
    }


    /* USING HASH-MAP
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
    */
};