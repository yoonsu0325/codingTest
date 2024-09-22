#include <iostream>
#include <algorithm>

using namespace std;

int W[101], V[101];
int D[101][100001];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> W[i] >> V[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= K; j++){
            if(j >= W[i]) D[i][j] = max(D[i-1][j],D[i-1][j-W[i]]+V[i]);
            else D[i][j] = D[i-1][j];
        }
    }

    cout << D[N][K];
}
