class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res = "1";
        for (;n > 1; --n){
            string tmp = "";
            for (int i = 0; i < res.size(); ++i){
                int count = 1;
                while (i + 1 < res.size() && res[i] == res[i+1]){
                    ++i;
                    ++count;
                }
                tmp += to_string(count) + res[i];
            }
            res = tmp;
        }
        return res;
    }
};