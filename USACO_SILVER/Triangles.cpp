#include <bits/stdc++.h>

using namespace std;

long long offset = 1e4;
long long mod = 1e9 + 7;
long long n;
vector<long long> x[20001], y[20001];
map<long long, long long> sx[20001], sy[20001];
vector<pair<long long,long long>> V;

int main()
{
cin.tie(0);
ios_base::sync_with_stdio();
cout.tie(0);

cin >> n;

for(int i=0;i<n;i++){
 long long a,b;
 cin >> a >> b;
 a+=offset;
 b+=offset;
 x[a].push_back(b);
 y[b].push_back(a);
 V.push_back({a,b});
}

for (int i = 0; i <= 20000; i++) {
sort(x[i].begin(), x[i].end());
sort(y[i].begin(), y[i].end());

long long sum = 0;

 for (auto& j : x[i]){
   sum += j - x[i][0];
   sum %= mod;
 }  
 for (int j = 0; j < x[i].size(); j++) {
 if (j!=0) {
 sum = (sum + (2 * j - x[i].size()) * (x[i][j] - x[i][j - 1])) % mod;
 if (sum < 0)
   sum += mod;
 }
 sx[i][x[i][j]] = sum;
 }
 
 sum = 0;

 for (auto& j : y[i]){
   sum += j - y[i][0];
   sum %= mod;
 }  
 for (int j = 0; j < y[i].size(); j++) {
 if (j!=0) {
 sum = (sum + (2 * j - y[i].size()) * (y[i][j] - y[i][j - 1])) % mod;
 if (sum < 0)
   sum += mod;
 }
 sy[i][y[i][j]] = sum;
 }
}

long long ans = 0;
for (int i=0;i<V.size();i++){
 long long a= V[i].first;
 long long b= V[i].second;
ans = (ans + sx[a][b] * sy[b][a]) % mod;
}
cout << ans << '\n';

}
