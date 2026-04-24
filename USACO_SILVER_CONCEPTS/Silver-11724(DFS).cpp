#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v[1005];
int arr[1005];

void dfs(int x){
    arr[x] = 1;
    for(int next : v[x]){
        if(arr[next] == 0) dfs(next);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i =0 ; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(arr[i] == 0){
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << "\n";
}