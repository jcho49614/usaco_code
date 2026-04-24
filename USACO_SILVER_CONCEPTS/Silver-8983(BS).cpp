#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// abs(shooting point - xcoord) + y coord
//use long long
int main(){
	long long a, b, distance;
	cin >> a >> b >> distance;

	long long arr[a];
	long long arr2[b][2];

	for(int i = 0; i < a; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < b; i++){
		cin >> arr2[i][0] >> arr2[i][1];
	}

	sort(arr, arr+a);

	int cnt = 0;

	for(int i = 0; i < b; i++){
		int lo = 0, hi = a - 1;
		while(lo <= hi){
			long long mid = (hi + lo) / 2;
			long long length = abs(arr[mid] - arr2[i][0]) + arr2[i][1];
			if(length <= distance){
				cnt++;
				break;
			}
			else{
				if(arr[mid] < arr2[i][0]){
					lo = mid +  1;
				}
				else if(arr[mid] > arr2[i][0]){
					hi = mid - 1;
				}
				else{
					break; //if its right on top 
				}
			}
		}
	}

	cout << cnt << "\n";
}