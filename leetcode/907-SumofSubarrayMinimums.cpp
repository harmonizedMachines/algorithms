class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        long ans = 0;
        for (int i = 0; i < arr.size() + 1; ++i){
            while (!s.empty() && (i == arr.size() || arr[i] <= arr[s.top()])) {
                int mid = s.top();
                s.pop();
                long left = s.empty() ? -1 : s.top();
                ans += (left - mid) * (mid - i) * arr[mid];
            }
            s.push(i);
        }
        return ans % 1000000007;
    }

    int sumSubarrayMinsDP(vector<int>& arr) {
        stack<int> s;
        vector<long> dp(arr.size());
        for (int i = 0; i < arr.size(); ++i){
            while (!s.empty() && arr[i] <= arr[s.top()]) {
                s.pop();
            }
            if (!s.empty()){
                dp[i] = arr[i] * (i - s.top()) + dp[s.top()];
            } else {
                dp[i] = arr[i] * (i + 1);
            }
            s.push(i);
        }
        long ans = 0;
        for (auto& i: dp){
            ans = (ans + i) % 1000000007;
        }
        return ans;
    }
};