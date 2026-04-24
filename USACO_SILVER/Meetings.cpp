#include <iostream>
#include <tuple>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

//use of array? no i dont think need
vector<tuple<int, int, int>> cows;
vector<pair<int, int>> leftcows;
vector<pair<int, int>> rightcows;

int totalweight = 0;
//something to track position? no no need...?

int main(){

	int n, m; cin >> n >> m;
	//n is cow number, m is length and shit

	for(int i =0 ; i < n; i++){
		int a, b, c;
		//weight, position, "speed?" "inertia?"
		cin >> a >> b >> c;
		cows.push_back(make_tuple(a,b,c));

		if(c < 0) leftcows.push_back(make_pair(a, b));
		else rightcows.push_back(make_pair(a,b));

		totalweight += a;
	}

	//making a tuple is much simpler. Now to find the left, right colliding.
	//left is classified to "-1", right is classified to "1".

	//STAGE 1: WHAT IS DIRECTED TO LEFT vs WHAT IS ACTUALLY ON THE LEFT.
	//if the positional one is the same, then make sure to make an exemption

	std::sort(cows.begin(), cows.end(), [](const auto& a, const auto& b) {
        return std::get<1>(a) < std::get<1>(b); // compare second element
    });


    std::sort(leftcows.begin(), leftcows.end(), [](const auto& a, const auto& b) {
        return std::get<1>(a) < std::get<1>(b); // compare second element
    });


    std::sort(rightcows.begin(), rightcows.end(), [](const auto& a, const auto& b) {
        return std::get<1>(a) < std::get<1>(b); // compare second element
    });


    vector<tuple<int, int, int>> finalcount; //first number is weight, second is left OR right wall.

	for(int i =0; i < leftcows.size(); i++){
		//compare leftcows to just cows, position i.
		//honestly i was too fucking lazy to do that lmaooo

		//OGPOS 1 will touch the LEFT WALL in LEFTPOS time.

		int currentpos = get<1>(leftcows[i]);
		int weight = get<0>(cows[i]);

		//now the "weight" cow will go to the wall in 'currentpos' time

		finalcount.push_back(make_tuple(currentpos, weight, -1));
	}

	for(int i =0; i < rightcows.size(); i++){
		//compare leftcows to just cows, position i.
		//honestly i was too fucking lazy to do that lmaooo

		//OGPOS 1 will touch the LEFT WALL in LEFTPOS time.

		int currentpos = get<1>(rightcows[rightcows.size() - i - 1]);
		int weight = get<0>(cows[cows.size() - i - 1]);

		//now the "weight" cow will go to the wall in 'currentpos' time

		finalcount.push_back(make_tuple(m - currentpos, weight, 1));
	}

	/*for(int i =0 ; i < finalcount.size(); i++){
		cout << get<0>(finalcount[i]) << " " << get<1>(finalcount[i]) << " " << get<2>(finalcount[i]) << "\n";
	}*/


	sort(finalcount.begin(), finalcount.end());

	long long current_weight = 0;
	int Time = 0;
	for(auto& event : finalcount) {
		current_weight += get<1>(event);
		if (current_weight * 2 >= totalweight) {
		    Time = get<0>(event);
		    break;
		}
	}

	


	int cnt = 0;



	vector<int> lCows;
  	vector<int> rCows;

 
  	for(int i=0;i<n;i++){
    	if(get<2>(cows[i]) == -1)
      		lCows.push_back(get<1>(cows[i]));
    	else
      		rCows.push_back(get<1>(cows[i]));
  	}
 
  	for(int i=0;i<lCows.size();i++){
    	int e = lower_bound(rCows.begin(), rCows.end(), lCows[i]) - rCows.begin();
    	int s = lower_bound(rCows.begin(), rCows.end(), lCows[i] - 2 * Time) - rCows.begin();
    	cnt += e-s;
  	}
 
  	cout << cnt;

}