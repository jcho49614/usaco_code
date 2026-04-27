#include <bits/stdc++.h>
using namespace std;

int num[5][100000];

int find(int x) {
  if(num[0][x] < 0) return x;
  else return num[0][x] = find(num[0][x]);
}

void merge(int a, int b) {
  int x = find(a);
  int y = find(b);
  if(x==y) return;
  num[1][y] = min(num[1][x], num[1][y]);
  num[2][y] = min(num[2][x], num[2][y]);
  num[3][y] = max(num[3][x], num[3][y]);
  num[4][y] = max(num[4][x], num[4][y]);
  num[0][x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M,A,B;
  int ans = 1e9;
  cin >> N >> M;
  for(int i=0; i<N; i++) {
    int x,y;
    cin >> x >> y;
    num[3][i] = num[1][i] = x;
    num[4][i] = num[2][i] = y;
  }
  for(int i=0; i<N; i++) {
    num[0][i] = -1;
  }
  for(int i=0; i<M; i++) {
    cin >> A >> B;
    A--;
    B--;
    merge(A, B);
  }

  for(int i=0;i<N;i++) {
    if(num[0][i] < 0){
      ans = min(ans, 2*(num[4][i]-num[2][i])+2*(num[3][i]-num[1][i]));
    }
  }
  cout << ans;
  return 0;
}