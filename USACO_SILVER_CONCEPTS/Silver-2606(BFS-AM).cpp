#include <iostream>
#include <queue>
using namespace std;

int v, e;
int arr[105][105];
int vis[105];

int main(){

    cin >> v >> e;
    for(int i =0 ; i < e; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int cn = q.front();
        q.pop();
        for(int i = 1; i <= v; i++){
            if(arr[cn][i] == 1 && vis[i] == 0){
                q.push(i);
                vis[i] = 1;
            }
        }
    }

    int cnt  =0;

    for(int i=1;i<=v;i++){
    if(vis[i]==1)
      cnt++;
    }


    cout<<cnt-1<<"\n";
}