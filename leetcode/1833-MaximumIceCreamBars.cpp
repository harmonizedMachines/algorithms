class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int cost: costs){
            if (coins - cost >= 0){
                ++count;
                coins -= cost;
            } else {
                return count;
            }
        }
        return count;
    }
};