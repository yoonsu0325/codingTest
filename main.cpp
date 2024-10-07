#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[31];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, result = 0;
    cin >> n;
    d[0] = 1;
    if(n%2!=1){
        d[2] = 3;
        d[4] = d[2] * d[2] + 2;
        for(int i=6; i<=n; i+=2){
            d[i] = d[i-2] * 6 - d[i-4] * 9 + d[i-6] * 2;
        }
    }
    result = d[n];
    cout << result;
}
