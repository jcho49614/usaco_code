#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a; cin >> a;
	for(int o = 0; o < a; o++){
		int n; cin >> n; int m; cin >> m;
		vector<int> v1;
		for(int i = 0; i < n; i++){
			int tmp; cin >> tmp; v1.push_back(tmp);
		}
		vector<int> v2;
		for(int i =0 ; i < m; i++){
			int tmp; cin >> tmp; v2.push_back(tmp);
		}

		sort(v1.begin(), v1.end());
		int cnt =0;
		for(int i =0; i < m; i++){
			int tmp = upper_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
			cnt += n - tmp;
		}

		cout << cnt << "\n";
	}
}