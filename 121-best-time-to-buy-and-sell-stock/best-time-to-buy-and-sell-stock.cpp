class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int mp = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minprice = min(minprice, prices[i]);
            profit = prices[i] - minprice;
            mp = max(mp, profit);
        }
        return mp;
    }
};