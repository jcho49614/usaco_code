#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> v1;
	for(int i = 0; i < n; i++){
		int tmp; cin >> tmp; v1.push_back(tmp);
	}

	int m; cin >> m;
	vector<int> v2;
	for(int i = 0; i < m ; i++){
		int tmp; cin >> tmp; v2.push_back(tmp);
	}

	sort(v1.begin(), v1.end());

	for(int i =0; i < m; i++){
		cout << ((lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin()) - (upper_bound(v1.begin(), v1.end(), v2[i]) - v1.begin())) * -1 << " ";
	}
}