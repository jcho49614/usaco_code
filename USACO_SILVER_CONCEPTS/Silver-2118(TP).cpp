#include <iostream>
using namespace std;
int arr[50005];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n; cin >> n;

	long long total = 0;

	for(int i =0 ; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	long long sumA = arr[0];
	long long sumB = total - arr[0];
	int lo = 0, hi = 0;
	long long ans = min(sumA,sumB);
	while(lo<n){
		if(sumA==sumB){
			ans=sumA;
			break;
		}
		else if(sumA<sumB){
			hi++;
			sumA+=arr[hi%n];
			sumB-=arr[hi%n];
			ans = max(ans,min(sumA,sumB));
		}
		else{
			sumA-=arr[lo%n];
			sumB+=arr[lo%n];
			lo++;
			ans = max(ans,min(sumA,sumB));
		}
	}
	cout << ans;
}