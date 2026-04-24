#include <iostream>

int aa[1000][1000];
int vis[1000];
int v, e;
using namespace std;

void dfsaa(int x){
    vis[x] = 1; // done so that visit array dont cause infinite
    for(int i = 1; i <= v; i++){
        if(aa[x][i] == 1 && vis[i] == 0){
            dfsaa(i);
            /*
            goes from dfs[1] and finds input.
            it it finds something that it might be linked to,
            it goes deeper (depth first)
            Afterwards it retracks.
            */
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    for(int i =0; i < e; i++){
        int x, y;
        cin >> x >> y;
        aa[x][y] = 1;
        aa[y][x] = 1; //bidirectional edges
    }

    dfsaa(1);

    int cnt = 0;
    bool sev = false;
    for(int i = 1; i <= v; i++){
        if(vis[i] != 1){

            cout << i << "\n";
            sev = true;
        }
    }
    if(sev == false){
        cout << 0 << "\n";
    }
}