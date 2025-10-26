#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int arr[n];


	int totalwaycnt=0; int lo = 0; int hi = -1;
	int tmpval = 0;

	while(true){
		if(hi == n) break;
		
		if(tmpval > n){
			while(tmpval > n){
				tmpval -= lo++;
			}
		}
		else if(tmpval < n){
			tmpval += ++hi;
		}	
		else{
			totalwaycnt++;
			tmpval -= lo++;
		}
	}

	cout << totalwaycnt << "\n";
}