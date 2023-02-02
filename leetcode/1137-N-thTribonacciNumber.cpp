class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribonacci = {0, 1, 1};
        if (n == 0){
            return 0;
        } else if (n == 1 || n == 2){
            return 1;
        }
        int size = tribonacci.size();
        while (size < n + 1){
            tribonacci.push_back(tribonacci[size - 3] + tribonacci[size - 2] + tribonacci[size - 1]);
            size++;
        }
        return tribonacci[n];
    }
};