#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio> // Required for freopen

using namespace std;

int n; 
int k; 
// Increased to 25 to prevent out-of-bounds crashing when tk == 20
int arr[100005][25][3]; 
char listarr[100005];

int hpscalc (char starting, char ending){        
    if(starting == 'H'){
        if(ending == 'H') return 0;
        if(ending == 'P') return 1;
        if(ending == 'S') return 0;
    }
    else if(starting == 'P'){
        if(ending == 'H') return 0;
        if(ending == 'P') return 0;
        if(ending == 'S') return 1;
    }
    else if(starting == 'S'){
        if(ending == 'H') return 1;
        if(ending == 'P') return 0;
        if(ending == 'S') return 0;
    }
    return 0; 
}

int main(){
    // USACO File I/O setup
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> k;        
    for(int i = 0 ; i < n; i++){
        cin >> listarr[i];
    }

    // Initialize base cases for the first game
    arr[0][0][0] = hpscalc(listarr[0], 'H');
    arr[0][0][1] = hpscalc(listarr[0], 'P');
    arr[0][0][2] = hpscalc(listarr[0], 'S');

    int maxwincondition = max({arr[0][0][0], arr[0][0][1], arr[0][0][2]});

    for(int i = 1; i < n; i++){
        for(int tk = 0; tk <= k; tk++){
            for(int j = 0; j <= 2; j++){
                if(j == 0) {
                    if(tk != 0) arr[i][tk][j] = (hpscalc(listarr[i], 'H') + max(arr[i-1][tk][j], max(arr[i-1][tk-1][1] , arr[i-1][tk-1][2])));
                    else arr[i][tk][j] = hpscalc(listarr[i], 'H') + arr[i-1][tk][j];
                    if (i == n - 1) maxwincondition = max(maxwincondition, arr[i][tk][j]);
                }
                else if(j == 1) {
                    if(tk != 0) arr[i][tk][j] = (hpscalc(listarr[i], 'P') + max(arr[i-1][tk][j], max(arr[i-1][tk-1][0] , arr[i-1][tk-1][2])));
                    else arr[i][tk][j] = hpscalc(listarr[i], 'P') + arr[i-1][tk][j];
                    if (i == n - 1) maxwincondition = max(maxwincondition, arr[i][tk][j]);
                }
                else if(j == 2) {
                    if(tk != 0) arr[i][tk][j] = (hpscalc(listarr[i], 'S') + max(arr[i-1][tk][j], max(arr[i-1][tk-1][1] , arr[i-1][tk-1][0])));
                    else arr[i][tk][j] = hpscalc(listarr[i], 'S') + arr[i-1][tk][j];
                    if (i == n - 1) maxwincondition = max(maxwincondition, arr[i][tk][j]);
                }
            }
        }
    }

    cout << maxwincondition << "\n";
    return 0;
}