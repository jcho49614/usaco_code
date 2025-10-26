#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	int n, m;
	cin >> n >> m;
	int arr[n];
	int arr2[m];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < m; i++){
		cin >> arr2[i];
	}

	sort(arr, arr+n,cmp);
	sort(arr2, arr2+m,cmp);

	int pointer = 0;
	int cnt = 0;

	for(int i = 0; i < n; i++){
		cnt++;
		bool a1 = false;
		while(arr[i] <= arr2[pointer]){
			pointer++;
			//cout << 1 << "\n";
		}

		if(arr[i] > arr2[pointer] && pointer < m){
			cnt++;
			pointer++;
			//cout << 2 << "\n";

		}
		else if(pointer >= m) continue;
	}

	cout << cnt << "\n";
}