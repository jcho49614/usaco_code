#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define llu long long

//a and b is under 10^18. Use Long long? --> is the interval. use pair<llu, llu> v.

int n, m; //n and m are the cow number requirement and number of intervals respectively.
vector<pair<llu, llu>> v; //the pairs of intervals that have under 10^18...

int main(){
    cin >> n >> m;
    for(int i =0; i < m; i++){
        llu a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    //now is sorted, time to go in binary search

    int minimum = 0; int maximum = v[v.size()-1].second / (n-1);

    int maxdistance = 0;
    while (minimum <= maximum){
        int potdistance = (maximum + minimum) / 2;
        
        int currentpos = v[0].first;
        int currentindex = 0;
        int cnt = 1;

        while(currentindex <= v.size()-1 && cnt<n){
            int temporary = currentpos + potdistance;
            if(temporary <= v[currentindex].second){
                cnt++; 
                if(temporary>=v[currentindex].first)
                    currentpos = temporary;
                else
                    currentpos = v[currentindex].first;
            } 
            else { //temporary has to default to the next one!
                currentindex++;
            }
        }

        if(cnt < n){ //this means that everything was insufficient! Lower D!
            maximum = potdistance - 1;
            //cout << potdistance << " ";
        }
        else if(cnt >= n){
            minimum = potdistance + 1;
            maxdistance = max(maxdistance, potdistance);
            //cout << potdistance << " ";
        }
    }

    cout << maxdistance << "\n";
}
