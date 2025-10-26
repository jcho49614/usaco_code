#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

void ibcincout() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(){
	ibcincout();

	ll n, m; cin >> n;
	ll arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	cin >> m;

	ll solution = 0;
	ll lo = 0; ll hi = arr[n-1];

	while(lo < hi){
		
		ll mid = (lo + hi + 1)/2;
		ll cnt =0;
		for(int i =0 ; i < n; i++){
			if(mid > arr[i]){
				cnt += arr[i];
			}
			else{
				cnt += mid;
			}
		}

		if(cnt > m){
			hi = mid-1;
		}
		else{
			lo = mid;
			solution = max(lo, solution);
		}
	}

	cout << solution << "\n";
}