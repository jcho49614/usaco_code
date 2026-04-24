#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> roadmap;
    set<int> a;

    
    for(int i =0; i < n ; i++){
        int tmp, tmp1; cin >> tmp >> tmp1;
        roadmap.push_back(make_pair(tmp, tmp1));
        a.insert(tmp1);
    }

    //sort basd on the first.

    int totalnumcount = a.size();

    sort(roadmap.begin(), roadmap.end());

    int lo = 0;
    int hi = 0;
    
    multiset<int> temp;
    

    temp.insert(roadmap[0].second);
    int mini = __INT32_MAX__;

    set<int> distinct(temp.begin(), temp.end());

    while(hi < n){
        //they're both at the lockat.

        /*
        
        Since they're both at the location, we
        need to make a modifier. make an
        initial set that contians the number.
        Afterwards, count and see if
        there's enough. if it doesn't work,
        add another one. If it does,
        remove one. record in min val.

        */

        int currentsize = distinct.size();

        if(currentsize < totalnumcount){
            hi++;
            int q = roadmap[hi].second;

            if(temp.find(q) != temp.end()){
                temp.insert(q);
            }
            else{
                distinct.insert(q);
                temp.insert(q);
            }
            //cout << 1;
        }
        else{
            mini = min(mini, roadmap[hi].first - roadmap[lo].first);
            temp.erase(temp.find(roadmap[lo].second));
            if(temp.find(roadmap[lo].second) == temp.end()){
                distinct.erase(roadmap[lo].second);
            }
            lo++;
            //cout << 2;
        }

    }

    cout << mini << "\n";

}