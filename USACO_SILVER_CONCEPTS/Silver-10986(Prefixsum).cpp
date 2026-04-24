#include <iostream>
using namespace std;

int main(){
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int visitarr[1000] = {0,};
    int arr[n+1];
    int cnt =0;
    for(int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        arr[i] = (arr[i-1] + tmp) % m;
        visitarr[arr[i]]++;
    }

    for(int i = 0; i < m; i++){
        if(i == 0){
            cnt += visitarr[i];
        }
        //nC2 = n * n-1/2!

        cnt += (visitarr[i] * (visitarr[i]-1) / 2);
    }

    cout << cnt << "\n";

}