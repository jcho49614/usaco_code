#include <iostream>
using namespace std;

int arr[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int tmp; cin >> tmp;
		arr[i] = tmp + arr[i-1];
	}
	int tmp; cin >> tmp;
	for(int i = 0; i < tmp; i++){
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		cout << arr[tmp2] - arr[tmp1-1] << "\n";
	}
}