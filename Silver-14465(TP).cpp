#include <iostream>
using namespace std;

int main(){
	int n, m, o;
	cin >> n >> m >> o;
	int arr[n] = {0,};
	for(int i =0 ; i < o ; i++){
		int tmp; cin >> tmp;
		arr[tmp-1]++;
	}

	//twopointer: 0-4.

	int lo = 0; int hi = m - 1;
	int minimum = __INT32_MAX__;
	int currentval = 0;
	for(int i =0 ; i <= hi; i++){
		currentval += arr[i];
	}

	while(true){
		currentval -= arr[lo];
		lo++;

		hi++;
		if(hi == n) break;
		currentval += arr[hi];

		minimum = min(currentval, minimum);
	}

	cout << minimum << "\n";
}