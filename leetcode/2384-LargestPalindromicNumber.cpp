class Solution {
public:
    string largestPalindromic(string num) {
        int freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        string front = "", back = "";
        for (auto digit: num){
            freq[digit - '0']++;
        }
        for (int i = 9; i >= 0; i--){
            if (i == 0 && front.empty())
                continue;
            
            while (freq[i] > 1){
                front += to_string(i);
                back += to_string(i);
                freq[i] -= 2;
            }
        }
        for (int i = 9; i >= 0; i--){
            if (freq[i] > 0){
                front += to_string(i);
                break;
            }
        }
        reverse(back.begin(), back.end());
        return front + back;
    }
};