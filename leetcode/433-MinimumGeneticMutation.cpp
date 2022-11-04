class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid(bank.begin(), bank.end());
        if (valid.find(endGene) == valid.end()){
            return -1;
        }
        int steps = 0;
        queue<string> q;
        q.push(startGene);
        while (!q.empty()){
            int n = q.size();
            while (n--){
                string s = q.front();
                if (s == endGene){
                    return steps;
                }
                q.pop();
                valid.erase(s);
                for (int i = 0; i < 8; ++i){
                    char curr = s[i];
                    s[i] = 'A';
                    if (valid.find(s) != valid.end()){
                        q.push(s);
                    }
                    s[i] = 'C';
                    if (valid.find(s) != valid.end()){
                        q.push(s);
                    }
                    s[i] = 'G';
                    if (valid.find(s) != valid.end()){
                        q.push(s);
                    }
                    s[i] = 'T';
                    if (valid.find(s) != valid.end()){
                        q.push(s);
                    }
                    s[i] = curr;
                }
            }
            ++steps;
        }
        return -1;
    }
};