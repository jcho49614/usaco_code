#include <iostream>
#include <deque>
using namespace std;



void solveproblem(){
    string s; cin >> s;
    deque<int> d;
    int n; cin >> n;
    for(int i =0; i < n; i++){
        char tmpchar; cin >> tmpchar;
        int tmp; cin >> tmp;
        d.push_back(tmp);
    }
    char tmpchar; cin >> tmpchar;
    
    bool checkreverse = false; // if false, remove from front. If true, remove from back.
    bool checkcontinue = false;
    for(int i =0; i < s.size(); i++){
        if(s[i] == 'R'){
            checkreverse = !checkreverse;
        }
        else{
            if(d.empty()){
                checkcontinue = true;
                break;
            }
            else{
                if(checkreverse == false){
                    d.pop_front();
                }
                else{
                    d.pop_back();
                }
            }
        }
    }
    
    if(checkcontinue == true){
        cout << "error" << "\n";
    }
    else{
        cout << '[';
        if(checkreverse == false){
            while(!d.empty()){
                cout << d.front();
                if(d.size() - 1 != 0){
                    cout << ',';
                }
                d.pop_front();
            }
        }
        else{
            while(!d.empty()){
                cout << d.back();
                if(d.size() - 1 != 0){
                    cout << ',';
                }
                d.pop_back();
            }
        }
        
        cout << ']' << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i =0 ; i < n; i++){
        solveproblem();
    }
}