#include <iostream>
#include <algorithm>
using namespace std;
//2,147,483,647
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n, m; cin >> n>> m;
	//n is nephew, m is number of candy.
	long long arr[m];
	for(long long i =0 ; i < m; i++){
		cin >> arr[i];
	}

	//lowest value: first value.
	//highest value: last value.
	//start from middle. if the value is ultimately 0, then return 0.
	sort(arr, arr+m);
	long long lo = 0; long long hi = arr[m - 1];
	long long solution = 0;
	while(lo < hi){
		long long middle = (lo + hi + 1)/2;

		//cout << lo << " " << hi << " " << middle << "\n";

		long long numcandy = 0;
		for(long long i =0; i < m; i++){
			numcandy += arr[i] / middle;
		}
		//if higher, then candy needs to be longer. lo = mid.
		//if lower, then candy needs to be shorter. hi = mid/	


		if(numcandy >= n){
			lo = middle;
			solution = middle;
		}
		else{
			hi = middle-1;
		}
	}

	cout << solution << "\n";
}