#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> Q;
    for(int i=0; i<n; i++){
        cin >> num;
        if(num == 0){
            if(Q.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << Q.top() << "\n";
                Q.pop();
            }
        }
        else{
            Q.push(num);
        }
    }

    return 0;
}