class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0;
        int profit = INT_MIN;

        while(r < prices.size()){
            profit = max(profit, prices[r]-prices[l]);
            if(prices[l] > prices[r]){
                l = r;
                r++;
            }
            else r++;
        }
        return profit;
    }
};