class Solution {
public:
    bool checkIfPangram(string sentence) {
        int check = 0;
        for (char i: sentence){
            check |= 1 << (i - 'a');
        }
        return check == (1 << 26) - 1;
    }
};