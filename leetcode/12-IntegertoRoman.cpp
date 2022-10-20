class Solution {
public:
    const int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string intToRoman(int num) {
        string ans = "";
        for (int i = 0; num; ++i){
            while (num >= nums[i]){
                ans += roman[i];
                num -= nums[i];
            }
        }
        return ans;
    }
};