#include <iostream>
#include <deque>
#include <vector>
#include <algorithm> //maybe, for sort?
#include <cstring>
using namespace std;

vector<int> v1;
vector<int> v2;
int visitarr[500005];
int pos[500005];
int arr[500005];

deque<int> abase;
deque<int> b1;
deque<int> b2;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for(int i = 0; i < k; i++){
		int tmp; cin >> tmp;
		v1.push_back(tmp);
		visitarr[tmp] += 1;
		pos[tmp]=i;
		abase.push_back(tmp);
	}
	for(int i =0; i < k; i++){
		int tmp; cin >> tmp;
		v2.push_back(tmp);
		visitarr[tmp] += 1;
		b1.push_back(tmp);
		b2.push_back(tmp);
	}

	int tmp = b2.front();
	b2.pop_front();
	reverse(b2.begin(), b2.end());
	b2.push_front(tmp);
	//this is our reversed b2.

	int totalcount  = 0;
	vector<int> possibleintegers; // to note the possible integers
	for(int i = 1; i <= n; i++){
		if(visitarr[i] == 2) possibleintegers.push_back(i);
		else if(visitarr[i] == 0) totalcount++;
	}
	//until here is done
	//i mean I could always just not use possibleintegers as I can check w/ the visit array.

	//comparison between the two

	// for(int i = 0; i < k; i++) cout << b1[i];
	// cout << endl;
	// for(int i = 0; i < k; i++) cout << b2[i];
	// cout << endl;

//PASSED UNTIL HERE.

	bool check = false;
	int maxinteger = 0;
	for(int attempt = 0; attempt < 2; attempt++){
		check ^= 1;
		for(int i = 0; i < k; i++){
			//round 1, round 2 comparison
			if(visitarr[abase[i]] == 2){
				if(check){
					//comparison of round 1. Use the base number of abase and i to find the distance.
					int tmp = abase[i]; //cout << tmp << " ";
					int checki = i;
					//cout << "testone";
					while(tmp != b1[checki % k]) checki++; //cout << checki << " ";
					arr[checki - i]++; //cout << checki-i << "\n";
				}
				else{
					//comparison of round 2. Use the base number of abase and i to find the distance.
					int tmp = abase[i]; //cout << tmp << " ";
					int checki = i;
					//cout << "testtwo";
					while(tmp != b2[checki % k]) checki++; //cout << checki << " ";
					arr[checki - i]++; //cout << checki-i << "\n";
				}
			}
		}
		for(int i = 0; i < n + 1; i++) maxinteger = max(maxinteger, arr[i]);
		memset(arr, 0, 500005);
	}

	cout << maxinteger + totalcount << "\n";
}	