#include <iostream>
#include <string>
using namespace std;

int arr[1505][1505];		//let's do 0 for down and 1 for right. Distinction between 1 -> N and N + 1;
//IF R: Increase j.
//IF D: Increase i.

int valuearr[1505][1505];
//this contains the pathways of each array value.
//currently all values of valuearr contains the amount 1.

int n;

int solvemap(int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(arr[i][j] == 0){
				//down
				if(i+1 == n + 1) continue;
				else valuearr[i+1][j] = valuearr[i+1][j] + valuearr[i][j];
			}
			else{
				if(j + 1 == n + 1) continue;
				else valuearr[i][j+1] = valuearr[i][j+1] + valuearr[i][j];
			}
		}
	}

	//now solve the total sum by calculating the N column.
	//there's a solid chance that it doesn't lead to n+1 so keep in mind.
	int totalcount =0;
	//first: j = n, i = 1 -> n - 1
	for(int i = 1; i <= n - 1; i++){
		if(arr[i][n] == 1) totalcount += (arr[i][n+1] * valuearr[i][n]);
	}
	for(int i = 1; i <= n - 1; i++){
		if(arr[n][i] == 0) totalcount += (arr[n+1][i] * valuearr[n][i]);
	}

	if(arr[n][n] == 0) totalcount += (valuearr[n][n] * arr[n+1][n]);
	else totalcount += (valuearr[n][n] * arr[n][n+1]);

	return totalcount;
}

int solvencolumns(int n){		//invoke this to find the total count.
	int totalcount =0;
	//first: j = n, i = 1 -> n - 1
	for(int i = 1; i <= n - 1; i++){
		if(arr[i][n] == 1) totalcount += (arr[i][n+1] * valuearr[i][n]);
	}
	for(int i = 1; i <= n - 1; i++){
		if(arr[n][i] == 0) totalcount += (arr[n+1][i] * valuearr[n][i]);
	}

	if(arr[n][n] == 0) totalcount += (valuearr[n][n] * arr[n+1][n]);
	else totalcount += (valuearr[n][n] * arr[n][n+1]);

	return totalcount;
}

int dfsremovevalue(int a, int b, bool direction){
	// The number of cows moving through (a, b) remains unchanged.
	// We only subtract this 'delta' from everything downstream along the OLD path.
	int delta = valuearr[a][b];
	
	if(direction) b++; // If old direction was Right, start tracking from the right neighbor
	else a++;          // If old direction was Down, start tracking from the bottom neighbor
	
	while(a <= n && b <= n){
		valuearr[a][b] -= delta;
		if(arr[a][b] == 1) b++;
		else a++;
	}
	return 0;
}

int dfsaddvalue(int a, int b, bool direction){
	// We add the 'delta' to everything downstream along the NEW path.
	int delta = valuearr[a][b];
	
	if(direction) b++; // If new direction is Right
	else a++;          // If new direction is Down
	
	while(a <= n && b <= n){
		valuearr[a][b] += delta;
		if(arr[a][b] == 1) b++;
		else a++;
	}
	return 0;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){		//one indexing, i = 1 to i = N.
		string s; cin >> s;
		int tmp; cin >> tmp;
		arr[i][n+1] = tmp;
		for(int j =1; j <= n; j++){
			if(s[j-1] == 'R') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	for(int i = 1; i <= n; i++){
		int tmp; cin >> tmp;
		arr[n+1][i] = tmp;
	}

	for(int i = 1; i <= n; i++){		 //setting every value of valuearr as 1. Initialization
		for(int j = 1; j <= n; j++){
			valuearr[i][j] = 1;
		}
	}

	// int m; cin >> m;

	cout << solvemap(n) << "\n";
	//this also intializes the valuearr for swapping proficiency.

	int m; cin >> m;
	for(int c = 0; c < m; c++){
		int a, b;
		cin >> a >> b;

		// 1. Trace the old path and subtract the current cell's flow from downstream cells
		dfsremovevalue(a, b, arr[a][b]);

		// 2. Flip the direction
		arr[a][b] ^= 1;		

		// 3. Trace the new path and add the current cell's flow to downstream cells
		dfsaddvalue(a, b, arr[a][b]);

		// 4. Output the updated total sum
		cout << solvencolumns(n) << "\n";
	}
}








