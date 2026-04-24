#include <iostream>
using namespace std;

int arr[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i  =0; i <  n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[a][b] += 1;
        arr[c][d] += 1;
        arr[a][d] += -1;
        arr[c][b] += -1;
    }

    int cnt  =0;

    for(int i =0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            arr[i+1][j] += arr[i][j];
            arr[i][j+1] += arr[i][j];
            arr[i+1][j+1] -= arr[i][j];
            if(arr[i][j] == m){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}