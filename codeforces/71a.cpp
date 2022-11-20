# include <iostream>
# include <string.h>
using namespace std;

int main(){
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        string temp;
        cin >> temp;
        if (temp.size() <= 10){
            cout << temp << endl;
            continue;
        }
        cout << temp[0] << (temp.size() - 2) << temp[temp.size() - 1] << endl;
    }
}