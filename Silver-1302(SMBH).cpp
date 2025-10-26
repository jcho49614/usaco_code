#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    multiset<string> ms;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        ms.insert(s);
    }

    int max =0;
    string ans;
    for(auto it = ms.begin(); it != ms.end(); it++){
        if(ms.count(*it) > max){
            max = ms.count(*it);
            ans = *it;
        }
    }

    cout << ans << "\n";
}