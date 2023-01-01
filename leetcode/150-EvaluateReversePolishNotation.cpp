class Solution {
public:
    stack<string> tokens;
    pair<int, int> fromStack(){
        int second = stoi(tokens.top());
        tokens.pop();
        int first = stoi(tokens.top());
        tokens.pop();
        return make_pair(first, second);
    }

    int evalRPN(vector<string>& inputtokens) {
        int res = 0;
        pair<int, int> nums;
        for (string& s: inputtokens){
            if (s.size() == 1){
                switch (s[0]){
                    case '+':
                        nums = fromStack();
                        tokens.push(to_string(nums.first + nums.second));
                        break;
                    case '-':
                        nums = fromStack();
                        tokens.push(to_string(nums.first - nums.second));
                        break;
                    case '*':
                        nums = fromStack();
                        tokens.push(to_string(nums.first * nums.second));
                        break;
                    case '/':
                        nums = fromStack();
                        tokens.push(to_string(nums.first / nums.second));
                        break;
                    default:
                        tokens.push(s);
                }
            } else {
                tokens.push(s);
            }
        }
        return stoi(tokens.top());
    }
};