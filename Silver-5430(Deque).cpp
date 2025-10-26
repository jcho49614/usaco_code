#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        string s; cin >> s;
        int tmp; cin >> tmp;
        deque<int> d;
        for(int i = 0; i < tmp; i++){
            char tmpchar; cin >> tmpchar;
            int tmpint; cin >> tmpint;
            d.push_back(tmpint);
        }
        char tmpchar; cin >> tmpchar;

        bool checkerror = false;
        bool checkreverse = false; //checkreverse false is push back, checkreverse true is push front
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R'){
                checkreverse = !checkreverse;
            }
            else{
                if(d.empty()){
                    checkerror = true;
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
            if(checkerror == true){
                break;
            }
        }
        if(checkerror == true){
            cout << "error" << "\n";
        }
        else{
            cout << '[' << "\n";
            if(checkreverse == false){
                while(deque)
            }
        }
    }
}