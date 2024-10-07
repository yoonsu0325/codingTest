#include <iostream>
#include <queue>
#include <string.h> //C++
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int map[1001][1001];
    int res[1001][1001];
    memset(res, -1, sizeof(res));
    int n, m, num;
    cin >> n >> m;
    queue<pair<int, int>> Q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> num;
            if(num == 2){
                Q.push(make_pair(i,j));
                res[i][j] = 0;
            }
            else if(num == 0){
                res[i][j] = 0;
            }
            map[i][j] = num;
        }
    }

    while(!Q.empty()){
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop();
        int distance = res[a][b];
        if(a + 1 < n && map[a+1][b] != 0 && res[a+1][b] == -1){
            res[a+1][b] = distance+1;
            Q.push(make_pair(a+1, b));
        }
        if(a - 1 >= 0 && map[a-1][b] != 0 && res[a-1][b] == -1){
            res[a-1][b] = distance+1;
            Q.push(make_pair(a-1, b));
        }
        if(b + 1 < m && map[a][b+1] != 0 && res[a][b+1] == -1){
            res[a][b+1] = distance+1;
            Q.push(make_pair(a, b+1));
        }
        if(b - 1 >= 0 && map[a][b-1] != 0 && res[a][b-1] == -1){
            res[a][b-1] = distance+1;
            Q.push(make_pair(a, b-1));
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

}