#include <iostream>
#include <queue>
#include <string.h> //C++
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int visit[200001];
    memset(visit, -1, sizeof(visit));
    queue<int> Q;
    Q.push(n);
    visit[n] = 0;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();

        if(x == k){
            cout << visit[x];
            break;
        }

        if(x < k && x*2 <= 200000 && visit[x*2] == -1){
            Q.push(x*2);
            visit[x*2] = visit[x];
        }
        if(x-1 >= 0 && visit[x-1] == -1){
            Q.push(x-1);
            visit[x-1] = visit[x]+1;
        }
        if(x+1 <= 200000 && visit[x+1] == -1){
            Q.push(x+1);
            visit[x+1] = visit[x]+1;
        }

    }
}