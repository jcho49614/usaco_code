#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        if(tmp == 0){
            if(s.empty()){
                cout << 0 << "\n";
            }
            else{
                auto it = s.begin();
                cout << *it << "\n";
                s.erase(s.find(*it));
            }
        }
        else{
            s.insert(tmp);
        }
    }
}