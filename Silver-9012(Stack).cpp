#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        stack<char> ss;
        int open = 0;
        bool check = false;
        for(int i  =0; i < s.size(); i++){
            ss.push(s[i]);
            if(ss.top() == '('){
                open++;
            }
            else if(open == 0 && ss.top()==')'){
                check = true;
                open--;
            }
            else{
                open--;
            }
        }

        if(open == 0 && check == false){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}