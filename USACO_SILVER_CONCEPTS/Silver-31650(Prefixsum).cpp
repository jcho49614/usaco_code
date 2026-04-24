#include<bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int N,Q; cin>>N>>Q;
 
  vector<int> c(N), t(N);
  vector<int> timeline(1000002);
 
  for(int i=0; i<N; i++) cin>>c[i];
  for(int i=0; i<N; i++) cin>>t[i];
 
  for(int i=0; i<N; i++)
  {
    int wake = c[i] - t[i]; // 이 목장은 S<wake 여야 방문할 수 있다.
    if(wake < 0) continue;
    timeline[wake]++;
  }

  for(int i=999999; i>=0; i--) // timeline을 누적합으로, timeline[i]에 기존 timeline[i~1000000]의 합을 저장
  {
    timeline[i] += timeline[i+1];
  }
  while(Q--)
  {
    int V,S; cin>>V>>S;
    if(timeline[S+1] >= V) cout<<"YES\n";
    else cout<<"NO\n";
  }
}