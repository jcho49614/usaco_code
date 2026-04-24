#include "bits/stdc++.h"

using namespace std;

int G[105][105]; //Adjunct Matrix
vector<int> L[105]; // Linked List
int vis1[105];
int vis2[105];
int V,E;
int cnt1,cnt2;

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
  queue<int> q;
  q.push(1);
  vis1[1] = 1;
  while(!q.empty()){
    int cn = q.front();
    q.pop();
    for(int i=1;i<=V;i++){
      if(G[cn][i]==1 && vis1[i]==0){
        q.push(i);
        vis1[i]=1;
      }
    }
  }
  //dfs1(1)
  for(int i=1;i<=V;i++){
    if(vis1[i]==1)
      cnt1++;
  }
  queue<int> q2;
  q2.push(1);
  vis2[1] = 1;
  while(!q2.empty()){
    int cn = q2.front();
    q2.pop();
    for(int i : L[cn]){
      if(vis2[i]==0){
        q2.push(i);
        vis2[i]=1;
      }
    }
  }
 
  //dfs2(1);
  for(int i=1;i<=V;i++){
    if(vis2[i]==1)
      cnt2++;
  }
  cout << cnt1 - 1;
}