# include <string>

string removeDuplicate(string s){
    int end = 0;
    for (int cur = 0; cur < s.size(); ++cur){
        if (end > 0 && s[end-1] == s[cur]){
            --end; // if remove both duplicate char
        } else {
            s[end++] = s[cur];
        }
    }
    return s.substr(0, end);
}