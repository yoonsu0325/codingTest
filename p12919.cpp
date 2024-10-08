#include <iostream>
#include <queue>
#include <algorithm>
#include <string> //C++
using namespace std;

int isSubstring(string a, string b){
    if(b.find(a) == string::npos){
        reverse(a.begin(), a.end());
        return b.find(a) != string::npos;
    }
    else return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    queue<string> Q;
    Q.push(s);
    int result = 0;
    while(!Q.empty()){
        string now = Q.front();
        Q.pop();

        if(now==t){
            result = 1;
            break;
        }

        if(now.length() == t.size()){
            continue;
        }

        if(isSubstring(now+"A", t))
            Q.push(now+"A");

        reverse(now.begin(), now.end());

        if(isSubstring("B" + now, t))
            Q.push("B" + now);

    }
    cout << result;
}