#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m; cin >> n >> m;
	ll arr[n];
	for(int i =0 ; i < n; i++){
		cin >> arr[i];
	}

	sort(arr, arr+n);
	ll lo, hi; lo = 0; hi = arr[n-1];

	while(lo < hi){
		ll mid = (lo+hi+1)/2;
		ll cnt = 0;
		for(int i = 0; i < n; i++){
			cnt += (arr[i] / mid);
		}

		//if cnt is lower, lower hi.
		//if cnt is higher, higher lo.

		if(cnt < m){
			hi = mid - 1;
		}
		else{
			lo = mid;
		}
	}

	cout << lo << "\n";
}