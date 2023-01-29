class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> cnt(K, 0);
        cnt[0] = 1;
        int prefix = 0, ans = 0;
        for (int& a: A){
            prefix = (prefix + a % K + K) % K;
            ans += cnt[prefix]++;
        }
        return ans;
    }
};
