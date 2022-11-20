#include <iostream>
using namespace std;

int main(){
    int n, m, a;
    cin >> n >> m >> a;
    printf("%.0lf", (double)(n / a + (n % a ? 1: 0)) * (double)(m / a + (m % a ? 1: 0)));
    return 0;
}