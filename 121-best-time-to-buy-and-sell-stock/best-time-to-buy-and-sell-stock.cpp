class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        int sell=0;
        for(int i=0; i<prices.size(); i++){
            buy=min(buy, prices[i]);
            sell=prices[i];
            profit = max(profit, sell - buy);
        }
        return profit;
    }
};