#include <iostream>
using namespace std;

int n;
int arr[102][102];
int visarr[102][102];

int totaledge = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void dfs(int x, int y){
    //totaledge adding time.
    if(arr[x][y]==1){
        totaledge++;
        return;
    }
    visarr[x][y] = 1;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx > 101 || ny < 0 || ny > 101) continue;
        if(visarr[nx][ny] == 0) dfs(nx, ny);
    }


}

int main(){
    cin >> n;
    for(int i =0 ; i < n; i++){
        int one, two; 
        cin >> one >> two;
        arr[two][one] = 1;
    }

    dfs(0, 0);
    cout << totaledge << "\n";
}