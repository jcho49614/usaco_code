#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n,k,m;

bool f(ll x) {
    ll rest = n;
    ll day = 0;
    while (true) {
        ll givePerday = rest / x;
        if (givePerday <= m) {
            ll ret = day + (rest + m-1) / m;
            return ret<=k;
        }
        ll leftMost = givePerday * x;
        ll dayCnt = (rest - leftMost + givePerday) / givePerday;

        day += dayCnt;
        if (day > k) return false;
        ll give = dayCnt * givePerday;
        rest -= give;
        if (rest <= 0) {
            break;
        }
    }

    return day <= k;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
 
  cin >> n >> k >> m;
  ll lo = 1;
  ll hi = n;
  ll ret = -1;
 
  while(lo<=hi){
    ll mid = (lo + hi) / 2;
    if (f(mid)){
      ret = mid;
      lo = mid+1;
    }
    else{
      hi = mid - 1;
    }
  }
 
  cout << ret;
  return 0;
}