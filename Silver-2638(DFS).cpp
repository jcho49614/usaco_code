#include <iostream>
using namespace std;

int n, m; //columns, rows
int arr[105][105]; //including buffer!
int visarr[105][105];//unidirectional, multidirectional doesn't matter
int countarr[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){
    if(arr[x][y] == 1) {
        countarr[x][y]++;
        return ;
    }
    visarr[x][y] = 1;

    //use of direction arrays
    for(int i =0 ; i < 4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        //direction arrays done. check for ones.
        
        if(nx < 0 || nx > 101 || ny < 0 || ny > 101) continue;

        if(visarr[nx][ny]==0) dfs(nx, ny);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i =1 ; i <= n; i++){
        for(int j =1 ; j <= m; j++){
            cin >> arr[i][j]; //0 if not, 1 if is. Adjunct matrix
        }
    }

    //steps:
    //step 1: find the 0s.
    //step 2: find the ones it collides paths with. -- log down visarr!
    //step 3: compare and contrast between countarr and normalarr and remove stuff.
    //step 4: check if all 0s.

    int rounds = 1;

    while(true){
        //reset the counting arrays
        for(int i =0 ; i < 105; i++){
            for(int j = 0; j < 105; j++){
                countarr[i][j] = 0;
                visarr[i][j] = 0;
            }
        }
        //find the 0s.
        dfs(0,0); //dfs 0 and 0. in this phase we add.

        for(int i =0 ; i < 105; i++){
            for(int j =0 ; j< 105; j++){
                if(countarr[i][j] > 1) {if(arr[i][j] == 1) arr[i][j] = 0;}
            }
        }
        bool check = true;

        for(int i =0 ; i < 105; i++){
            for(int j = 0; j < 105; j++){
                if(arr[i][j] == 1) check = false;
            }
        }
        if(check) {cout << rounds << "\n"; break;}
        else rounds++;
    }
}