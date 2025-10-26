#include <iostream>
#include <vector>
using namespace std;
int v;
int n;
char arr[100005];
vector<int> vec[100005];
int visarr[100005];

void dfs(int x, int c){
    visarr[x] = c;

    for(auto i : vec[x]){
        if(arr[i] == arr[x] && visarr[i] == 0) {
            dfs(i, c); 
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int v, n;
    cin >> v >> n;

    for(int i =0 ; i < v; i++){
        char tmp; cin >> tmp;
        arr[i+1] = tmp;
    }
    
    for(int i =0 ; i < v - 1; i++){
        int tmp1; int tmp2;
        cin >> tmp1 >> tmp2;
        vec[tmp1].push_back(tmp2);
        vec[tmp2].push_back(tmp1);
    }
    int num = 1;
    for(int i =1; i <= v; i++){
        if(visarr[i] == 0) {dfs(i, num); num++;}
    }

    for(int i = 0; i < n; i++){
        int a, b; char c;
        cin >> a >> b >> c;
        if(arr[a] == c || visarr[a] != visarr[b]) cout << 1;
        else cout << 0;
    }
}