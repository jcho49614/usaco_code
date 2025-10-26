#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<int> ss1;
    stack<int> ss2;
    stack<int> ss3;
    int n; cin >> n;
    for(int i = n; i >= 1; i--){
        ss1.push(i);
    }
    int l, m;
    while(cin >> l >> m){
        if(l == 1){
            for(int i = 0; i < m; i++){
                ss2.push(ss1.top());
                ss1.pop();
            }
        }
        else{
            for(int i =0; i < m; i++){
                ss3.push(ss2.top());
                ss2.pop();
            }
        }
    }

    //for(int i  =0; i < ss3.size(); i++){
    while(!ss3.empty()){
        cout << ss3.top() << "\n";
        ss3.pop();
    }
}