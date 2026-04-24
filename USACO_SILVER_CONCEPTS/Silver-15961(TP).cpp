#include <iostream>
using namespace std;

int main(){
	int a, b, c, d;
	int cnt = 0;
	cin >> a >> b >> c >> d;
	int arr2[b + 5] = {0,};
	int arr[2 * a + 5];
	for(int i =0 ; i < a; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < a; i++){
		arr[i+a] = arr[i];
	}

	int lo = 0; int hi = c - 1;
	for(int i =0 ; i <= c-1; i++){
		if(arr2[arr[i]]==0) cnt++;
		arr2[arr[i]]++;
	}
	int maxvariety = 0;
	if(arr2[d]==0) maxvariety = max(cnt+1,maxvariety);
	else maxvariety = max(cnt, maxvariety);

	while(lo != a){
		cout << maxvariety << endl;
		lo++; hi++;		

		arr2[arr[lo-1]]--;
		if(arr2[arr[lo-1]]==0) cnt--;
		if(arr2[arr[hi]]==0) cnt++;
		arr2[arr[hi]]++;

		if(arr2[d]==0) maxvariety = max(cnt+1,maxvariety);
		else maxvariety = max(cnt, maxvariety);
	}
	cout << maxvariety;
}