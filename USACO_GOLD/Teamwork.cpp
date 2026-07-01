#include <iostream>
#include <utility>
using namespace std;

int dparr[10005];
int cows[10005];
int cowsmax[10005];

int main(){
	int n; int groupcount; cin >> n >> groupcount;
	for(int i =0 ; i < n; i++){
		int tmp; cin >> tmp;
		cows[i] = tmp;
	}

	//iterate through everything ONCE and get the best possible result.

	int maximum = 0;

	for(int i = 0; i < groupcount; i++){
		//for every single one, you can't possibly have the max amount of individuals here.
		//we need to be wary of this, because "max" value will ALWAYS be grouping everyone together.
		int tmp = cows[i];	//cows i is going to be i + 1st
		maximum = max(tmp, maximum);
		dparr[i] = maximum * (i+1);
		cowsmax[i] = maximum;
	}

	//now we have the more.

	for(int i = 0; i < n; i++){
		int currentmax = 0;
		dparr[i] = 0;
		//check trhough all previous iterations.
		for(int j= 1; j <= groupcount && i-j+1>=0; j++){
			//i is the group amount.
			currentmax = max(cows[i-j+1], currentmax);
			dparr[i] = max(currentmax*j+dparr[i-j], dparr[i]);
		}
	}
	cout << dparr[n - 1] << "\n";

}