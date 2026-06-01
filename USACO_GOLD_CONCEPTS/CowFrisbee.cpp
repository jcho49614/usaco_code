#include <iostream>
#include <stack>
using namespace std;
int arr[100005];
stack<int> s;
stack<int> location;

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	//going from start to finish, using stacks to work it properly.


	s.push(arr[0]);
	location.push(0);

	int distancecount = 0;

	for(int i =1 ; i < n; i++){
		//get the value from the array, add distance between it, (pop if smaller), and push.
		int tmp = arr[i];
		//first add it to the ones right before.
		distancecount += 1;	//for the distancecount.

		int tmpn = i;

		while(tmpn >= 0){
			//find the value, check if it's smaller, and delete.
			//if larger, then break out of the loop.
			if (s.top() < tmp){
				//find distance
				int distance = (i - location.top() + 1);
				distancecount += distance;
				location.pop();
				s.pop();
			}
			else{
				int distance = (i-location.top() + 1);
				distancecount += distance;
			}
		}

		location.push(i);
		s.push(arr[i]);
	}

	cout << distancecount << "\n";
}