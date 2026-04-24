#include <iostream>
#include <vector>

using namespace std;

int G[105][105]; //Adjunct Matrix
vector<int> L[105]; // Linked List
int vis1[105];
int vis2[105];
int V,E;
int cnt1,cnt2;

void dfs1(int x){ //Adjunct Matrix
  vis1[x]=1;
  for(int i=1;i<=V;i++){
    if(G[x][i]==1 && vis1[i]==0){ //노드 X랑 연결 되어있는지 확인하고 방문한적 없는 노드인지 확인한다.
      dfs1(i);
    }
  }
}

void dfs2(int x){//Linked List
  vis2[x]=1;
  for(int next : L[x]){
    if(vis2[next]==0)
      dfs2(next);
  }
}

int main(){
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
 
  cin >> V;
  cin >> E;
  for(int i=0;i<E;i++){
    int x,y;
    cin >> x >> y;
    G[x][y] = 1;
    G[y][x] = 1;
    L[x].push_back(y); 
  }
  // for(int i=1;i<=V;i++){
  //   if(vis[i]==0) dfs(i);
  // }
  dfs1(1);
  for(int i=1;i<=V;i++){
    if(vis1[i]==1)
      cnt1++;
  }
  dfs2(1);
  for(int i=1;i<=V;i++){
    if(vis2[i]==1)
      cnt2++;
  }
  cout << cnt1 - 1 << cnt2 - 1;
}