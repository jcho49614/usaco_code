#include <iostream>
#include <deque>
using namespace std;

int main(){
    int t; cin >> t;
    for(int a = 0; a < t; a++){
        deque<char> s1;
        deque<char> s2;
        string s; cin >> s;
        for(int i =0 ; i < s.size(); i++){
            if(s[i] == '>'){
                if(!s2.empty()){
                    s1.push_back(s2.front());
                    s2.pop_front();
                }
            }
            else if(s[i] == '<'){
                if(!s1.empty()){
                    s2.push_front(s1.back());
                    s1.pop_back();
                }
            }
            else if(s[i] == '-'){
                if(!s1.empty()){
                    s1.pop_back();
                }
            }
            else{
                s1.push_back(s[i]);
            }
        }

        while(!s1.empty()){
            cout << s1.front();
            s1.pop_front();
        }
        while(!s2.empty()){
            cout << s2.front();
            s2.pop_front();
        }

        cout << "\n";
    }
}