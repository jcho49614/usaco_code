#include <iostream>
#include <vector>
using namespace std;

int n, m;
/*normal input v[number] pair(x,y)*/ vector<int> v1[100005];
/*linked list?*/ vector<int> v2[100005];
/*visarr*/ int visarr[100005];

int minperimeter = __INT32_MAX__;

int highx, lowx, highy, lowy;

void dfs(int x){
    //step1 find x's point.
    visarr[x] = 1;
    int a = v1[x][0];
    int b = v1[x][1];

    highx = max(highx, a);
    lowx = min(lowx, a);
    highy = max(highy, b);
    lowy = min(lowy, b);

    for(auto nx : v2[x]){
        if(visarr[nx]==0)
            dfs(nx);
    }

}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i =0 ; i < n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v1[i+1].push_back(tmp1);
        v1[i+1].push_back(tmp2);
    }

    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v2[tmp1].push_back(tmp2);
        v2[tmp2].push_back(tmp1);
    }

    for(int i = 1; i <= n; i++){
        if(visarr[i] == 0){
            highx = 0; lowx = __INT32_MAX__;
            highy = 0; lowy = __INT32_MAX__;
            dfs(i);
            //perimeter solving.
            minperimeter = min(minperimeter, ((highx-lowx)+(highy-lowy))*2);
        }
    }

    cout << minperimeter << "\n";
}