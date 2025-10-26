#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<string> s;
    set<string> s1;
    int cnt =0;
    for(int i = 0; i < n + m; i++){
        string tmp; cin >> tmp;
        if(s.count(tmp) == 1){
            s1.insert(tmp);
            cnt++;
            s.erase(tmp);
        }
        else{
            s.insert(tmp);
        }
    }

    cout << cnt << "\n";
    for(auto it = s1.begin(); it != s1.end(); it++){
        cout << *it << "\n";
    }
    
}