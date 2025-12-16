#include <iostream>
using namespace std;

int arr[1005][1005];

int main(){
	int n; cin >> n;
	for(int i =0 ; i < n; i++){
		for(int j =0 ; j < n; j++){
			cin >> arr[i][j];
		}
	}

	//row based
	//two types: starts with CHOOSE or doesn't start with CHOOSE. N * 2 different combinations.

	//how to keep track :( do I use binary numbers? yes I do.

	int rows = 0;
	int columns = 0;

	for(int i =0; i < n; i++){
		//this is for the rows.
		int a = 0, b = 0;
		for(int j = 0; j < n; j += 2){
			a += arr[i][j];
		}
		for(int j = 1; j < n; j+=2){
			b += arr[i][j];
		}

		rows += max(a, b);
	}

	for(int i =0; i < n; i++){
		//this is for the columns.
		int a = 0, b = 0;
		for(int j = 0; j < n; j += 2){
			a += arr[j][i];
		}
		for(int j = 1; j < n; j+=2){
			b += arr[j][i];
		}

		columns += max(a, b);
	}


	cout << max(rows, columns) << "\n";
}