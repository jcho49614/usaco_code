#include <iostream>
using namespace std;

int arr[1005][1005];
int darr[1005][1005];

int main(){
    int n, m, t;
    cin >> n >> m >> t;
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            darr[i][j] = darr[i-1][j] + darr[i][j-1] - darr[i-1][j-1] + arr[i][j];
        }
    }

    for(int i =0; i < t; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        int area = (c-a) * (d - b);
        int cnt = darr[c][d] - darr[a][d] - darr[c][b] + darr[a][b];
        cout << cnt / area << "\n";
    }
}