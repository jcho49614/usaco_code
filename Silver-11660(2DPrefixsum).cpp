#include <iostream>
using namespace std;

int arr[1050][1050];
int darr[1050][1050];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
            darr[i][j] = darr[i-1][j] + darr[i][j-1] - darr[i-1][j-1] + arr[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--;
        int cnt = darr[c][d] - darr[a][d] - darr[c][b] + darr[a][b];
        cout << cnt << "\n";

    }
}