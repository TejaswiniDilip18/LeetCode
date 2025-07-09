class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0;
        int profit = 0;

        while(r < prices.size()){
            if((prices[r]-prices[l]) > profit){
                profit = prices[r]-prices[l];
            }

            if(prices[l] > prices[r]){
                l = r;
            }
            r++;           
        }
        return profit;
    }
};