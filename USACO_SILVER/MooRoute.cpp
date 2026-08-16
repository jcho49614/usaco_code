#include <iostream>
using namespace std;
int arr[100005];
int main(){
	int n; cin >> n;
	for(int i =0; i < n; i++){
		int tmp; cin >> tmp; arr[i] = tmp;
	}
	arr[n] = 0;

	bool direction = 1; //1 is right, 0 is left
	//there are no failure clauses.
	int position = 0;	//starts off at 0.
	while(true){
		if(position == 0 && arr[0] == 0) break;
		
			//now checking if the next value is a zero to go back.
		while(arr[position] != 0){
			arr[position]--;
			position++;
			cout << 'R';
		}
		while(position != 0 && (arr[position - 1] > 1 || arr[position] == 0)){
			arr[position-1]--;
			position--;
			cout << 'L';
		}
	}

	cout << endl;
}