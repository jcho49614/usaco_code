#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
int main(){
	int n, m;
	cin >> n;
	for(int i =0 ; i < n; i++){
		cin >> arr[i];
	}
	cin >> m;
	sort(arr, arr+n);

	int lo = 0; int hi = n - 1;
	int sum = arr[lo] + arr[hi];

	int cnt  =0;
	while(lo < hi){
		if(sum < m){
			sum -= arr[lo];
			lo++;
			sum += arr[lo];
			//cout << 1;
		}
		else if(sum > m){
			sum -= arr[hi];
			hi--;
			sum += arr[hi];
			//cout << 2;
		}
		else{
			cnt++;
			cout << lo << " " << hi << " " << arr[lo] << " " << arr[hi] << " " << endl;
			sum -= arr[lo]; sum -= arr[hi];
			lo++; hi--;
			sum += arr[lo]; sum += arr[hi];

		}
	}

	cout << cnt << "\n";
}