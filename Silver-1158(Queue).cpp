//queue??
#include <iostream>
#include <queue>
using namespace std;
int arr[5005];

int main(){
    queue<int> q;
    int n, m; cin >> n >> m;
    int cnt[n];
    for(int i =0 ; i < n; i++){
        cnt[i] = i + 1;
    }

    int currentpos = 0;
    for(int i =0; i < n; i++){
        int tmp = 0;
        
        for(int j = 0; j < m; j++){
            currentpos++;
            if(currentpos > n){
                currentpos -= n;
            }
            bool check = false;
            while(check == false){
                if(arr[currentpos] == 1){
                    currentpos++;
                  /// cout << "(1)Attempted " << currentpos - 1 << ". " << "FAIL" << "\n";
                    if(currentpos > n){
                        currentpos -= n;
                    }
                }
                else{
                    check = true;
                    // cout << "(1)Attempted " << currentpos << ". " << "SUCCESS. ADDING 1" << "\n";
                }
            }
        }
        if(currentpos > n){
                currentpos -= n;
        }
        
        bool subcheck = false; 
        while(subcheck == 0){
            if(arr[currentpos] != 0){
                currentpos++;

             //  cout << "(2)Attempted " << currentpos - 1 << ". " << "FAIL" << "\n";
            }
            else{
                arr[currentpos]++;
                subcheck = true;
                q.push(currentpos);

                
              // cout << "(2)Attempted " << currentpos << ". " << "SUCCESS. ADDING 1" << "\n";
            }
        }
    }

    cout << "<";

    for(int i = 0; i < n; i++){
        if(i == n-1){
            cout << q.front();
            q.pop();
        }
        else{
            cout << q.front() << "," << " ";
            q.pop();
        }
    }

    cout << ">" << "\n";
}