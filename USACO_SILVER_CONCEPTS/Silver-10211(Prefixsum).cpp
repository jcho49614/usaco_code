#include <iostream>
using namespace std;

int main(){
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a; cin >> a;
    for(int l = 0; l < a; l++){
        int n; cin >> n;
        int arr[n+1];
        for(int i =1; i < n + 1; i++){
            int tmp;
            cin >> tmp;
            arr[i] = arr[i-1] + tmp;
        }
        int maximum = -1;
        for(int i =1; i < n + 1; i++){
            for(int j = 1; j < n+1; j++){
                if(j>i){
                    continue;

                }
                maximum = max(maximum, arr[i] - arr[j]);
            }
        }

        cout << maximum << "\n";
    }
}