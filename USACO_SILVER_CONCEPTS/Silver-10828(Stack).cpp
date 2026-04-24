#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<int> ss;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "push"){
            int tmp; cin >> tmp;
            ss.push(tmp);
        }
        else if(s == "top"){
            if(ss.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << ss.top() << "\n";
            }
        }
        else if(s == "empty"){
            cout << ss.empty() << "\n";
        }
        else if(s == "pop"){
            if(ss.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << ss.top() << "\n";
                ss.pop();
            }
        }
        else if(s == "size"){
            cout << ss.size() << "\n";
        }
    }
}