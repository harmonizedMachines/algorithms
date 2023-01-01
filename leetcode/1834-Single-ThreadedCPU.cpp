class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap;
        for (int i = 0; i < tasks.size(); ++i){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        vector<int> ans;
        long curTime = 0, i = 0;
        while (i < tasks.size() || !minheap.empty()){
            if (minheap.empty()){
                curTime = max(curTime, (long)tasks[i][0]);
            }
            while (i < tasks.size() && tasks[i][0] <= curTime){
                minheap.push({tasks[i][1], tasks[i][2]});
                ++i;
            }
            ans.push_back(minheap.top().second);
            curTime += minheap.top().first;
            minheap.pop();
        }
        return ans;
    }
};