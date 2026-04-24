#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for(int i =0 ; i < n; i++){
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	for(int o = 0; o < m; o++){
		int a, b; cin >> a >> b;
		cout << ((lower_bound(v.begin(), v.end(), a) - v.begin()) - (upper_bound(v.begin(), v.end(), b) - v.begin())) * -1 << "\n";
	}
}