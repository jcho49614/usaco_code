#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, m; cin >> n >> m;
	int arr[n];
	for(int i =0 ; i < n; i++){
		cin >> arr[i];
	}


	int cnt = 0; int lo = 0; int hi = -1;
	int tmpcnt = 0;
	while(hi < n){

		if(tmpcnt > m){
			tmpcnt -= arr[lo];
			lo++;
		}
		else if(tmpcnt < m){
			hi++;
			tmpcnt += arr[hi];
		}
		else{
			cnt++;
			tmpcnt -= arr[lo];
			lo++; hi++;
			tmpcnt += arr[hi];
		}
	}

	cout << cnt << "\n";
}