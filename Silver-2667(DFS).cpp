#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[30][30];
int vis[30][30];
int deltax[4] = {1, 0, -1, 0};
int deltay[4] = {0, 1, 0, -1};

int currentcnt = 1;


void dfs(int x, int y){
    vis[x][y] = 1;
    for(int i =0 ; i < 4; i++){
        int nx = x+deltax[i];
        int ny = y+deltay[i];
        if(nx<0 || nx >=n || ny <0 || ny>=n) continue;
        if(vis[nx][ny]==0 && arr[nx][ny]==1){
            currentcnt++;
            dfs(nx, ny);
        }
    }
}

int main(){
    cin >> n;
    for(int i =0 ; i < n; i++){
        string tmp; cin >> tmp;
        for(int j = 0; j < n; j++){
            char t = tmp[j];
            arr[i][j] = t - 48;
            //first element is row, second element is column
        }
    }
    vector<int> v;

    int cnt =0 ;
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 0 && arr[i][j] == 1){
                dfs(i, j);
                v.push_back(currentcnt);
                currentcnt = 1;
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() <<"\n";
    for(int i =0 ; i < v.size(); i++){
        cout << v[i] << "\n";
    }
}