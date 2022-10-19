class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for (int i = 0; i < colors.size() - 1; ++i){
            if (colors[i] == colors[i+1]){
                int minus = neededTime[i];
                ans += minus;
                while (i < colors.size() - 1 && colors[i+1] == colors[i]){
                    ans += neededTime[++i];
                    minus = max(minus, neededTime[i]);
                }
                ans -= minus;
            }
        }
        return ans;
    }
};