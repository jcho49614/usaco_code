#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, m; cin >> n >> m;
	int arr[n];
	for(int i =0 ; i < n; i++){
		cin >> arr[i];
	}

	sort(arr, arr+n);

	int cnt = 0; int lo = 0; int hi = 1;

	while(hi != n + 1){
		int tmpcnt = 0;
		for(int i =lo; i < hi; i++){
			tmpcnt += arr[i];
		}

		if(tmpcnt < m){
			lo++;
		}
		else if(tmpcnt > m){
			hi++;
		}
		else{
			cnt++;
			lo++; hi++;
		}
	}

	cout << cnt << "\n";
}