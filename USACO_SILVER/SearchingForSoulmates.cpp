/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int temp; cin >> temp;
	for(int i = 0;i < temp; i++){
		int firstnum, secondnum;
		cin >> firstnum >> secondnum;

		int fc, sc; fc = firstnum; sc = secondnum;

		//log down the secondnum down, w/ bitwise shift.
		vector<pair<int,int>> v;
		//the first number represents the secondnum reduced, second number represents steps taken
		v.push_back(make_pair(secondnum, 0));
		int stepcount = 0;
		while(sc != 1){
			if(__builtin_popcount(sc) != __builtin_popcount(sc >> 1)){
				stepcount += 2; sc = sc >> 1;
			}
			else{
				stepcount++; sc = sc >> 1;
			}
			v.push_back(make_pair(sc, stepcount));
		}

		// for(int i = 0; i < v.size(); i++){
		// 	int first = v[i].first;
		// 	int second = v[i].second;
		// 	cout << first << " " << second << "\n";
		// }

		int totalcount = 0;
		int minimuminteger = INT32_MAX;

		if(firstnum > secondnum){
			while(fc > sc){
				if(fc % 2 == 1) fc++;
				else fc /= 2;
				totalcount++;
			}

			//now we have a smaller value than secondnum.
		}

		//we now guess and check. 0, 1, 2, 3, 4, 5, 6, etc etc etc

		int vectorpos = 0;

		while(fc != 1){
			//calculate the first value first.
			//vectorpos 1. get the closest value?
			while(v[vectorpos+1].first <= fc) vectorpos++;
			//okay now we have the most optimal vectorpos value

			int difference = fc - v[vectorpos].first;
			//now we add the value of total count to vectorpos.second
			minimuminteger = min(difference + totalcount + v[vectorpos].second, minimuminteger);


			//now we find the next value or sum idk
			//if odd then add 1, blah blah blha
			//if even then divide

			if(fc % 2 == 1){
				fc++; fc /= 2; totalcount+= 2;
			}
			else{
				fc /= 2; totalcount++;
			}

		}

		cout << minimuminteger << "\n";

	}
}*/

#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long cow1, cow2;
        cin >> cow1 >> cow2;

        long long answer = LLONG_MAX;

        for (int removed = 0; (cow2 >> removed) > 0; ++removed) {
            long long here = 0;
            long long prefix = cow2 >> removed;
            long long cow = cow1;

            while (cow > prefix) {
                if (cow % 2 == 1) {
                    cow++;
                    here++;
                }
                cow /= 2;
                here++;
            }

            here += prefix - cow;
            here += removed;
            here += __builtin_popcountll(cow2 & ((1LL << removed) - 1));

            answer = min(answer, here);
        }

        cout << answer << '\n';
    }

    return 0;
}

