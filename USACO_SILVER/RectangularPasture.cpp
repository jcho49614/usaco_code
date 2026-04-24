#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

//return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]

int arr[2505][2505];
int prefix[2505][2505];

int xcoords[2505];
int ycoords[2505];

vector<pair<pair<int,int> ,int>> vx;
vector<pair<pair<int,int> ,int>> vy;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		vx.push_back(make_pair(make_pair(a,b), i));
		vy.push_back(make_pair(make_pair(b,a), i));
		cout << '(' << a << ',' << b << ')' << "\n";
	}
	
	
	//now create a noraml arr. I need to 1 index it.
	   
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	
	//based on the THIRD index, we sort...?
	//i is the coordinate value. It's the coordinates.

	for(int i = 0; i < vx.size(); i++){
		//sorted by vx.first.first
		//need to add value of vx.second
		xcoords[vx[i].second + 1] = i + 1;
	}
	for(int i = 0; i < vx.size(); i++){
		//sorted by vy.first.second
		ycoords[vy[i].second + 1] = i + 1;
	}

	//im going to test print the coordinates here.
	for(int i =1 ; i <= n; i++){
		cout << xcoords[i] << "," << ycoords[i] << "\n";
	}

	//now time to plug in the values of the array into the main array
	for(int i =1; i <= n; i++){
		arr[xcoords[i]][ycoords[i]] = 1;
	}
	
	//now create prefix arr
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			prefix[i][j] = arr[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << prefix[i][j] << " ";
		}
		cout << "\n";
	}
}