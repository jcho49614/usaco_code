#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int cnt = 0;
    int cnt1 = 0;
    
    for(;;){
        for(int i =0; i < 26; i++){
            cout << a[i] << " ";
            if(a[i] == b[cnt]) {cnt++; cout << "MATCH" << "\n";}
            else cout << "NOMATCH" << "\n";
        }
        if(cnt == b.size()) break;
        else cnt1++;
    }

    cout << cnt1 + 1 << "\n";
}