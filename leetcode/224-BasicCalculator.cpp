class Solution {
public:
    int calculate(string s) {
        int total = 0;
        stack<int> signs({1, 1});
        for (int i = 0; i < s.size(); ++i){
            switch (s[i]){
                case ')':
                    signs.pop();
                    break;
                case ' ':
                    break;
                case '+':
                case '-':
                    signs.push(signs.top() * (s[i] == '-' ? -1 : 1));
                    break;
                case '(':
                    signs.push(signs.top());
                    if (s[i + 1] == '-'){
                        s[i--] = '0';
                    }
                    break;
                default:
                    int num = 0;
                    while (i < s.size() && s[i] >= '0'){
                        num = num * 10 + (s[i++] - '0');
                    }
                    total += signs.top() * num;
                    signs.pop();
                    --i;
            }
        }
        return total;
    }
};