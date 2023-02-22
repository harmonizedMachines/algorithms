class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end()), hi = INT_MAX;
        while (lo < hi){
            int mid = lo + (hi - lo) / 2, need = 1, cur = 0;
            for (int i = 0; i < weights.size() && need <= days; cur += weights[i++]){
                if (cur + weights[i] > mid){
                    cur = 0, need++;
                }
            }
            if (need > days){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};