#include <iostream>
#define llu long long
using namespace std;

//"Loan Repayment", Silver January 2020

llu n, k, m; 		//cow number, days, minimum amount of milk per days

bool function(llu x){
	llu rest = n;
	llu day = 0;
	
	while(true){
		llu gpd = rest / x;
		if(gpd <= m){
			llu ret = day + (rest + m-1) / m;
			return ret <= k;
		}
		llu leftmost = gpd * x;
		llu daycount = (rest - leftmost + gpd) / gpd;
		
		day += daycount;
		if (day > k) return false;
		llu give = daycount * gpd;
		
		rest -= give;
		if(rest <= 0){
			break;
		}
	}
	return day <= k;
}

int main(){
	cin >> n >> k >> m;	
	
	llu high = n;			//high value
	llu low = 1;			//low value
	llu ret = -1;
	
	llu medium = 0;			//the medium value
	
	while(high >= low){					//teach's method to coding
		medium = (high + low) / 2; 		//goes lower if not a complete solution
		//medium is the value of x.
		bool check = function(medium);
		if(check){
			ret = medium;
			low = medium + 1;
		}
		else{
			high = medium - 1;
		}
	}
	
	cout << ret << "\n";
}