class Solution {
public:
    int fibonacci(int n, vector<int>& fib){
        if(n<=1){
            return 1;
        }

        if(fib[n] != -1){
            return fib[n];
        }

        fib[n] = fibonacci(n-1, fib) + fibonacci(n-2, fib);

        return fib[n];        
    }

    int climbStairs(int n) {
        vector<int> fib(n+1,-1);
        return fibonacci(n, fib);
    }
};