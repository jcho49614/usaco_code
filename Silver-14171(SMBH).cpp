#include <iostream>
#include <map>
using namespace std;

map<string, string> m;
map<pair<string, string>, int> mcount;

int cnt = 0;

void pre(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solveproblem(){
	string s1, s2;
	cin >> s1 >> s2;
	string s3 = s1.substr(0,2);
	if (s2 == s3) return;
	cnt += mcount[make_pair(s3,s2)];
	m[s2] = s3;
	mcount[make_pair(s2, s3)]++;
}

int main(){
	pre();

	int n; cin >> n;
	for(int a =0 ; a < n; a++){
		solveproblem();
	}

	cout << cnt << "\n";
}