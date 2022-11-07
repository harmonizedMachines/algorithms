class Solution {
public:
    int maximum69Number (int num) {
        int numcopy = num;
        int indexfirstsix = -1;
        int currdigit = 0;
        while (numcopy > 0){
            if (numcopy % 10 == 6){
                indexfirstsix = currdigit;
            }
            numcopy /= 10;
            ++currdigit;
        }
        return indexfirstsix == -1 ? num: num + 3 * pow(10, indexfirstsix);
    }
};