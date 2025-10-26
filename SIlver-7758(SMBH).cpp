#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    set<string> s;
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(s2 == "enter") s.insert(s1);
        else s.erase(s1);
    }

    vector<string> v;
    for(auto it = s.begin(); it != s.end(); it++){
        v.push_back(*it);
    }
    
    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i] << "\n";
    }
}