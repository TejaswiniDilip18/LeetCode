class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int profit = 0;

        while(right < prices.size()){
            profit = max(profit, (prices[right]-prices[left]));

            if(prices[left] > prices[right] && right > left){
                left = right;
            }
            right++;
        }
        return profit;
    }
};