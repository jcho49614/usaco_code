#include <iostream>
using namespace std;

//implement a direction array -- left, bottom, right, top.

int n;
char aa[105][105]; //written as 0.
int vis1[105][105]; //visit array.
int vis2[105][105]; //visit array.

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs1(int x, int y, char c){
    vis1[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        //cout << nx << ny << endl;
        if(nx<0 || nx >=n || ny <0 || ny>=n) continue;
        if(vis1[nx][ny]==0 && aa[nx][ny] == c) dfs1(nx,ny,c);
    }
}

void dfs2(int x, int y, char color){
    vis2[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx >=n || ny <0 || ny>=n) continue;
        if(vis2[nx][ny]==0){
            int find1;
            int find2;
            if(aa[nx][ny] == 'G' || aa[nx][ny] == 'R') find1 = 0;
            else find1 = 1;

            if(color== 'G' || color == 'R') find2 = 0;
            else find2 = 1;

            if(find1==find2) dfs2(nx, ny, aa[nx][ny]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i =0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> aa[i][j];
            //second one is rl, first one is td
            // vis1[i][j] = 0; //precaution
            // vis2[i][j] = 0; //precaution
        }
    }

    //dfs1 --> no distinction.
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        for(int j =0 ; j < n; j++){
            if(vis1[i][j] == 0){
                dfs1(i,j,aa[i][j]);
          
                cnt1++;
            }
        }
    }

    int cnt2 = 0;
    for(int i =0 ; i < n; i++){
        for(int j =0 ; j < n; j++){
            if(vis2[i][j] == 0){
                dfs2(i,j, aa[i][j]);
                cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2 << "\n";
}
