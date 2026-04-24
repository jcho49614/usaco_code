#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i =0 ; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);

    int lo = 0, hi = 0, lowest = __INT32_MAX__;
    int val = abs(arr[lo] - arr[hi]);


   while(hi < n){
        //found the value of val.
        if(val < m){
            int tmp = arr[hi];
            hi++;
            val += arr[hi];
            val -= tmp;
        }
        else{
            lowest = min(lowest, val);
            val += arr[lo];
            lo++;
            val -= arr[lo];
        }
    }

    cout << lowest << "\n";
}