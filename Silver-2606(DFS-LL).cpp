#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<int> ll[105];
int vis[105];

void dfs(int x){
    vis[x] = 1;
    for(int next : ll[x]){ //for indexes in 1d vector ll[x]
        dfs(next);
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
        ll[x].push_back(y); //2D vector!
    } 

    dfs(1);
    int cnt = 0;
    for(int i = 1; i <= v; i++){
        if(vis[i] == 1){
            cnt++;
        }
    }

    cout << cnt - 1 << "\n";

}