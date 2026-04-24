#include <iostream>
using namespace std;

int arr[1005][1005];

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char tmp; cin >> tmp;
			if(tmp == 'L') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}

	//using excluded or functoin

	//now first get the outer layer
	//find patterns?
	

}