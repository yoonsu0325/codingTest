#include <iostream>
#include <queue>
#include <string.h> //C++
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, num;
    cin >> n >> k;
    int nums[100001];
    memset(nums, 0, sizeof(nums));

    int count = 0;
    int maxcount = 1;
    queue <int> Q;
    for(int i=0; i<n; i++){
        cin >> num;
        Q.push(num);
        count ++;
        if(nums[num] + 1 <= k){
            nums[num] += 1;
        }
        else{
            while(!Q.empty()){
                int temp = Q.front();
                Q.pop();
                count --;
                if(temp == num){
                    break;
                }
                else{
                    nums[temp] -= 1;
                }
            }

        }
        maxcount = max(count, maxcount);
    }
    cout << maxcount;

}