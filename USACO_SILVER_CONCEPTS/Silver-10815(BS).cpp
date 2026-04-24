#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n; int arr[n];
	for(int i =0 ; i < n; i++){
		int tmp; cin >> tmp; arr[i] = tmp;
	}
	sort(arr, arr+n);

	cin >> m;	
	for(int i =0 ; i < m; i++){
		int tmp; cin >> tmp;
		bool answer = false;
		int lb = 0; int ub = n-1;
		while(lb <= ub){
			int mid = (lb + ub) / 2;
			if(arr[mid] < tmp){
				lb = mid + 1;
			}
			else if(arr[mid] > tmp){
				ub = mid - 1;
			}
			else{
				answer = true;
				break;
			}
		}

		if(answer == false){
			cout << "0 ";
		}
		else{
			cout << "1 ";
		}
	}
}