class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int x = a.size() - 1, y = b.size() - 1, c = 0;
        while (x >= 0 || y >= 0 || c == 1){
            c += x >= 0 ? a[x--] - '0': 0;
            c += y >= 0 ? b[y--] - '0': 0;
            ans = char((c & 1) + '0') + ans;
            c >>= 1;
        }
        return ans;
    }
};