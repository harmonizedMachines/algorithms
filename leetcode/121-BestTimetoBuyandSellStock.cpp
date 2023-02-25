class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i: prices){
            if (i < minPrice){
                minPrice = i;
            } else if (maxProfit < i - minPrice){
                maxProfit = i - minPrice;
            }
        }
        return maxProfit;
    }
};