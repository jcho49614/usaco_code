#include <iostream>
using namespace std;
int visarr[100000];

int main(){
	int n, m; cin >> n >> m;
	int arr[n];
	for(int i =0 ; i < n; i++){
		cin >> arr[i];
	}

	int lo = 0; int hi = -1; int cnt = 0;
	

	int maxvalue = 0;

	bool noovercount = true;

	while(true){
		if(noovercount == true){
			hi++;
			if(hi==n) break;
			visarr[arr[hi]]++;
			if(visarr[arr[hi]] > m){
				while(true){
					if(arr[lo] == arr[hi]){
						visarr[arr[lo]]--;
						lo++;
						break;
					}
					else{
						visarr[arr[lo]]--;
						lo++;
					}
				}
			}
		}

		maxvalue = max(maxvalue, hi - lo + 1);
	}

	cout << maxvalue << "\n";
}