#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
int input[3005][3005] = {0};
int pre[3005][3005] = {0};
int add[3005][3005] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;

void bfs(int y, int x){
  queue <pair<int, int> > q;
  if (pre[y][x] == 3){
    q.push(make_pair(y, x));
  }
  for (int i = 0; i < 4; i++){
    if(!add[y][x])
      pre[y+dy[i]][x+dx[i]]++;
    if (pre[y+dy[i]][x+dx[i]] == 3 && (input[y+dy[i]][x+dx[i]] || add[y+dy[i]][x+dx[i]])){
      q.push(make_pair(y+dy[i], x+dx[i]));
    }
  }
 
  if(add[y][x]){
    add[y][x] = 0;
    ans--;
  }
  while (!q.empty()){
    int yy = q.front().first;
    int xx = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int ny = yy + dy[i];
      int nx = xx + dx[i];
     
      if(!input[ny][nx] && !add[ny][nx]){
        ans++;
        add[ny][nx] = 1;
        if (pre[ny][nx]==3){
          q.push(make_pair(ny,nx));
        }
       
        for(int j=0;j<4;j++){
          int nny = ny + dy[j];
          int nnx = nx + dx[j];
          pre[nny][nnx]++;
         
          if(pre[nny][nnx] == 3 && (input[nny][nnx] || add[nny][nnx])){
            q.push(make_pair(nny,nnx));
          }
        }
      }
    }
  }
  cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        int a, b;
        cin >> b >> a;
        a+=1000;
        b+=1000;
        input[b][a] = 1;
        bfs(b, a);
    }
    return 0;
}
