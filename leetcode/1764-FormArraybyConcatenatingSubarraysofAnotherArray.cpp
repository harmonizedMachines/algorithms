class Solution {
public:
    int m, n;
    vector<int> lps;
    
    vector<int> lps(){
        int j = 0;
        for (int i = 0; i < str.length(); i++){
            if (str[i] == str[j]){
                j++;
                lps[i] = j;
            } else {
                while (j != 0){
                    j = lps[j - 1];
                    if (str[i] == str[j]){
                        j++;
                        lps[i] = j;
                        break;
                    }
                }
            }
        }
        return lps;
    }
    
    void kmp(){
        int[] lps = lps();
        int i = 0;
        int j = 0;
        while (i < text.length()){
            if (text[i] == pattern[i]){
                i++, j++;
            } else{
                if (j != 0){
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
            if (j == pattern.length()){
                return i - j;
            }
        }
        return -1;
    }
    
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        m = groups.size();
        n = nums.size();
        
        
    }
};