class Solution {
public:
    /* Method 1: Memoization
    int fibonacci(int n, vector<int>& fib){
        if(n<=1){
            return 1;
        }

        if(fib[n] != -1){
            return fib[n];
        }

        fib[n] = fibonacci(n-1, fib) + fibonacci(n-2, fib);

        return fib[n];        
    } */

    int climbStairs(int n) {
        // vector<int> fib(n+1,-1); // Method 1: Memoization
        // return fibonacci(n, fib); // Method 1: Memoization

        vector<int> fib(n+1, 0);
        fib[1]=1;
        if(n==1) return 1;

        fib[2] = 2;

        for(int i=3; i<=n ; i++){
            fib[i] = fib[i-1] + fib[i-2];
        }  

        return fib[n];      
    }
};