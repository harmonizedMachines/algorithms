class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2){
            return 0;
        }
        int has0buy = -prices[0], has1sell = 0, has0nth = 0, has1nth = -prices[0];
        for (int i = 1; i < prices.size(); ++i){
            has1nth = max(has0buy, has1nth);
            has0buy = has0nth - prices[i];
            has0nth = max(has0nth, has1sell);
            has1sell = has1nth + prices[i];
        }
        return max(has0nth, has1sell);
    }
};