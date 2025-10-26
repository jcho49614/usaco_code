#include <iostream>
//adjunct matrix!

using namespace std;

int w,h; //down is 1, right is 1.
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int vis[55][55];
int G[55][55];

void dfs(int x, int y){
    vis[x][y]=1;
    for(int i=0;i<8;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || nx >=h || ny <0 || ny>=w) continue;
        if(vis[nx][ny]==0 && G[nx][ny]==1) dfs(nx,ny);
    }
}

void solve(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> G[i][j];

            vis[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(vis[i][j]==0 && G[i][j]==1){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    while(true){
        cin >> w >> h;
        if(w==0 && h==0)
            break;
        solve();
    }
}