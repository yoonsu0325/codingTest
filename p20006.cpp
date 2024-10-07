#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<pair<int, string>>> v;

    int p, l, m;
    string n;
    cin >> p >> m;
    for(int i=0; i<p; i++){
        cin >> l >> n;
        bool sig = false;
        if(!v.empty()){
            for(int i=0; i<v.size(); i++){
                int level = v[i].front().first;
                if(v[i].size() < m && (level+10 >= l && level-10 <= l)) {
                    v[i].push_back(make_pair(l, n));
                    sig = true;
                    break;
                }
            }
        }
        if(!sig){
            vector<pair<int, string>> room;
            room.push_back(make_pair(l, n));
            v.push_back(room);
        }

    }

    for(auto r: v){
        if(r.size() == m){
            cout << "Started!\n";
        }
        else{
            cout << "Waiting!\n";
        }
        sort(r.begin(), r.end(), compare);
        for(auto pl : r){
            cout << pl.first << " " << pl.second << "\n";
        }
    }

}