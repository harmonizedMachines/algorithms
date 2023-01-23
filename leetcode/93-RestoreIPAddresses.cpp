class Solution {
private:
    bool check(string s){
        if (s.size() == 1){
            return true;
        }
        if (s.size() > 3 || s[0] == '0'){
            return false;
        }
        if (stoi(s) < 256){
            return true;
        }
        return false;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.size() > 12){
            return ans;
        }
        for (int a = 1; a <= 3; ++a){
            for (int b = 1; b <= 3; ++b){
                for (int c = 1; c <= 3; ++c){
                    if (a + b + c < s.size() && a + b + c + 3 >= s.size()){
                        string x = s.substr(0, a);
                        string y = s.substr(a, b);
                        string z = s.substr(a + b, c);
                        string q = s.substr(a + b + c);
                        if (check(x) && check(y) && check(z) && check(q)){
                            ans.push_back(x + '.' + y + '.' + z + '.' + q);
                        }
                    }
                }
            }
        }
        return ans;
    }
};