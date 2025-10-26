#include <iostream>
using namespace std;

long long arr[1000005];
long long ps[1000005];
int main(){

	#define int long long

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	//n is size of field, m is size of window on one side
	for(int i = 1; i <= n; i++){
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		arr[tmp2] = tmp1;
	}

//prefixsum
	for(int i = 1; i <= 1000005; i++){
		ps[i] = arr[i] + ps[i-1];
	}

	//add 2m+1. 1 - 7; 2 - 8; 3- 9;

	int maximum = 0;
	

	if(2 * m + 1 > 1000005){
		maximum = ps[1000005];
	}
	else{
		for(int i = 2*m+1; i <= 1000005; i++){
			if(maximum < ps[i] - ps[i-(2*m+1)]){
				maximum = ps[i] - ps[i-(2*m+1)];
			}
		}
	}

	
	cout << maximum << "\n";


}