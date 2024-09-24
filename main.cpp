#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[10001];
vector<int> coin;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    fill_n(d, 10001, 10001);
    int num;

    for(int i=0; i<n; i++){
        cin >> num;
        if(k>=num){
            coin.push_back(num);
            d[num] = 1;
        }

    }

    sort(coin.begin(), coin.end());

    for(int i=0; i<coin.size(); i++){
        for(int j=coin[i]; j<=k; j++){
            if(j%coin[i] == 0) d[j] = min(d[j], j/coin[i]);
            else{
                for(int l=1; l<=j/coin[i]; l++){
                    d[j] = min(d[j], l + d[j - l*coin[i]]);
                }

            }
        }
    }

    int result = d[k];
    if(result >= 10001) result = -1;
    cout << result;
    return 0;
}
