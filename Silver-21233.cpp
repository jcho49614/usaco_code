#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v;
vector<int>mot;
set<int> s;

int main(){
	int n, m;
	cin >> n >> m;
	for(int i =0 ; i < n; i++){
		int tmp; cin >> tmp; v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	//find the individual chunks
	//find the differences of the chunks
	//thorugh k find what I have to delete yes siree


	for(int i =0 ; i < v.size(); i++){
		int a = v[i] / 12 + 1;
		s.insert(a);
	}


	//find the differencen

	vector<int> v2;
	int prv = 0;
	for(auto i : s){
		v2.push_back(i-prv);
		prv=i;
	}

	//subtract 1!

	sort(v2.begin(), v2.end());

	//based on k, I need to sum the values of v2.size() - k.

	int cnt = 0;

	for(int i = 0; i < v2.size() - m+1; i++){
		cnt += v2[i];
	}
	cout << (cnt + (m-1))*12 << "\n";
}