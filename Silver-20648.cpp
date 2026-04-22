#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

//return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]

int arr[2505][2505];
int prefix[2505][2505];

vector<pair<int, pair<int,int>>> vx;
vector<pair<int, pair<int,int>>> vy;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		vx.push_back(make_pair(make_pair(a,b), i));
		vy.push_back(make_pair(make_pair(b,a), i));
	}
	
	
	//now create a noraml arr. I need to 1 index it.
	   
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	
	
	
	//now create prefix arr
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			prefix[i][j] = arr[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << prefix[i][j] << " ";
		}
		cout << "\n";
	}
}