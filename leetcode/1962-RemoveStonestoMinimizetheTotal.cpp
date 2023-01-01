class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());
        int res = accumulate(piles.begin(), piles.end(), 0);
        while (k--){
            int temp = heap.top();
            heap.pop();
            heap.push(temp - temp / 2);
            res -= temp / 2;
        }
        return res;
    }
};