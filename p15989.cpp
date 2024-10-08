#include <iostream>
#include <queue>
#include <string.h> //C++
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, num;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> num;
        if(num <= 5) cout << num << "\n";
        else{
            int ans = 0;
            int div = num/3;
            for(int j=0; j<=div; j++){
                int temp = num - j*3;
                ans += temp/2 + 1;
            }
            cout << ans << "\n";
        }
    }
}