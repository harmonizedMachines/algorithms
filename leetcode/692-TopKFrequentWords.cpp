struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b){
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (auto word: words){
            map[word]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        for (auto p: map){
            q.push({p.second, p.first});
        }
        vector<string> ans;
        while (k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};