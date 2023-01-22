class Solution {
private:
    vector<vector<string>> ans; 
    bool isPalindrome(string& s, int start, int end){
        while (start <= end){
            if (s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    void dfs(string& s, int index, vector<string>& path){
        if (index == s.size()){
            ans.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i){
            if (isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1, path);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, 0, path);
        return ans;
    }
};