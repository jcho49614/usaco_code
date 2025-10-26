#include <iostream>
#include <algorithm>
using namespace std;
//hoof, paper, scissors -- hoof - 0, paper - 1, scissors - 3

/*
planning:
1. input the character array
2. make individual prefix-sum arrays for H, P, S
3. make the 3-phase FOR Function: first and second for determining the H, P, S, and
third for the determining factor
3a. In here compare itself with the max.
*/
int n, a[100005][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
//1,2
    for(int i =1 ; i <= n; i++){
        char tmp; cin >> tmp;
        for(int j = 0; j < 3; j++){
            a[i][j] = a[i-1][j];
        }
        if(tmp == 'H') a[i][0] = a[i-1][0] + 1;
        else if(tmp == 'P') a[i][1] = a[i-1][1] + 1;
        else a[i][2] = a[i-1][2] + 1;
    }



//3
    int maximum = 0;
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3; j++){
            for(int k = 1; k <= n; k++){
                maximum = max(maximum, a[k-1][i] - a[k-1][j] + a[n][j]);
            }
        }
    }

    cout << maximum << "\n";
}