#include <iostream>
#include <tuple>
#include <deque>
using namespace std;

tuple<int, int, int> arr[100005];
deque<tuple<int, int, int>> dq;

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		//tmp1 is time arrival, tmp2 is time eating.
		arr[i] = make_tuple(tmp1, i+1, tmp2);
	}
	
	sort(arr, arr+n);

	
}