#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> ss;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            ss.pop();
        }
        else{
            ss.push(tmp);
        }
    }

    int cnt = 0;
    while(!ss.empty()){
        cnt+= ss.top();
        ss.pop();
    }

    cout << cnt << "\n";
}