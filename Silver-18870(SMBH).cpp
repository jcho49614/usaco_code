#include <iostream>
#include <set>
#include <map>
using namespace std;


int arr[1000005];
set<int> s;
map<int, int> m;

void pre(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solveproblem(int n){
	for(int i =0 ; i < n; i++){
		s.insert(arr[i]);
	}
	int cnt = 0;
	for(auto it = s.begin(); it != s.end(); it++){
		m[*it] = cnt;
		cnt++;
	}

	for(int i = 0; i < n; i++){
		cout << m[arr[i]] << "\n";
	}
}


int main(){
	pre();
	int n; cin >> n;
	for(int i =0 ; i < n; i++){
		cin >> arr[i];
	}

	solveproblem(n);
}