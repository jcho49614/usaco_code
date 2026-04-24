#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long n, m; cin >> n >> m;
    long long arr[n][2];
    long long minimumspicy = __INT64_MAX__;

    for(int i =0 ; i < n; i++){
        long long tmp, tmp1;
        cin >> tmp >> tmp1;
        arr[i][0] = tmp;
        arr[i][1] = tmp1;
        if(tmp>=m) minimumspicy = min(tmp1,minimumspicy);
    }

    int lo = 0; int hi = 0;
    long long flavor = 0;

    multiset<long long> ms; //for current spiciness..

    //finding the value: *it.

    //ms.insert(blah)

    while(true){
        while(flavor < m && hi < n){
            //add new
            
            flavor += arr[hi][0];
            ms.insert(arr[hi][1]);
            hi++;
        }
        while(flavor>=m && lo < n){
            //this is when it is enough.
            //step 1: find spiciness.
            if(!ms.empty()){
                auto it = ms.end();
                it--;
                long long tmp = *it;
                minimumspicy = min(tmp, minimumspicy);

                //step 2: remove lo from ms then remove lo from flavor then add 1 to lo.
                
                ms.erase(ms.find(arr[lo][1]));

                flavor -= arr[lo][0];
                lo++;
            }
        }
        if(hi>=n || lo>=n) break;
    }

    cout << minimumspicy;
}