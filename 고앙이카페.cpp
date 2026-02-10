#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> catweight;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	int cat, limit; cin >> cat >> limit;
	for(int i = 0; i < cat; i++){
		int tmp; cin >> tmp; catweight.push_back(tmp);
	}

	//sort
	sort(catweight.begin(), catweight.end());

	//twopointer
	int l = 0; int r = cat - 1;
	int happypeople = 0;

	while(l < r){
		//find the value. sum > limit, bump r down. sum < limit, bump both down.
		int tempval = catweight[l] + catweight[r];
		if(tempval > limit) r--;
		else {happypeople++; l++; r--;}
	}

	cout << happypeople << "\n";
}