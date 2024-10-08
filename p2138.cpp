#include <iostream>
#include <queue>
using namespace std;

int lights[100001], result[100001];

bool isEqual(int n){
    for(int i=0; i<n; i++){
        if(lights[i] != result[i]) return false;
    }
    return true;
}

int dp(int i, int count, int n){

    if(i == n){
        if(isEqual(n)){
            return count;
        }
        return 100001;
    }
    int ans = 100001;

    if(i == n-1) {
        if(lights[i-1] != result[i-1]){
            int a, b;
            a = lights[i-1];
            b = lights[i];
            lights[i-1] = !a;
            lights[i] = !b;

            ans = min(ans, dp(i+1, count+1, n));

            lights[i-1] = a;
            lights[i] = b;
        }
        else{
            ans = min(ans, dp(i+1, count, n));
        }
    }
    else{
        if(lights[i-1] != result[i-1]){
            int a, b, c;
            a = lights[i-1];
            b = lights[i];
            c = lights[i+1];
            lights[i-1] = !a;
            lights[i] = !b;
            lights[i+1] = !c;

            ans = min(ans, dp(i+1, count+1, n));

            lights[i-1] = a;
            lights[i] = b;
            lights[i+1] = c;

        }
        else{
            ans = min(ans, dp(i+1, count, n));
        }
    }

    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string a, b;

    int ans;
    cin >> a >> b;
    for(int i=0; i<n; i++){
        lights[i] = a[i] - '0';
        result[i] = b[i] - '0';
    }

    ans = dp(1,0, n);
    int x = lights[0];
    int y = lights[1];
    lights[0] = !x;
    lights[1] = !y;

    ans = min(ans, dp(1, 1, n));

    if(ans == 100001) ans = -1;
    cout << ans;
}