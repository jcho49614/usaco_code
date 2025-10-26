#include <iostream>
using namespace std;

int nrows, mcolumns; //we're only going to focus on the mcolumns, first nrows for stuff!

int arr[1005][1005];
int vis[1005][1005];

int deltax[4] = {1, 0, -1, 0};
int deltay[4] = {0, 1, 0, -1};

bool works = false;

void dfs(int nr, int mc){
    vis[nr][mc] = 1;

    cout << nr << " " << mc << "\n";
    cout << "_________________________\n";

    if(nr == nrows - 1){
        works = true;
        return;
    }

    for(int i =0 ; i < 4; i++){
        int nx = nr + deltax[i];
        int ny = mc + deltay[i];

        if(nx<0 || nx >= nrows || ny <0 || ny>=mcolumns) continue;
        if(vis[nx][ny]==0 && arr[nx][ny] == 0) dfs(nx,ny);

    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> nrows >> mcolumns;
    for(int i =0 ; i < nrows; i++){
        for(int j =0; j < mcolumns; j++){
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp - 48;
            vis[i][j] = 0;
        }
    }


    for(int i =0 ; i < mcolumns; i++){
        //nrows is automatically 0.
        if(arr[0][i] == 0 && vis[0][i] == 0){
            dfs(0, i);
            if(works) break;
        }
    }

    if(works) cout << "YES" << "\n";
    else cout << "NO" << "\n";

}