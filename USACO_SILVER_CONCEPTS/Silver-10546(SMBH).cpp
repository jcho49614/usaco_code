#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<string> s;
    int n; cin >> n;
    for(int i  =0; i < n; i++){
        string st; cin >> st;
        if(s.count(st) == 0){
            s.insert(st);
        }
        else{
            s.erase(st);
        }
    }

    for(int i = 1; i < n; i++){
        string st; cin >> st;
        if(s.count(st) == 0){
            s.insert(st);
        }
        else{
            s.erase(st);
        }
    }
    cout << *s.begin();
}