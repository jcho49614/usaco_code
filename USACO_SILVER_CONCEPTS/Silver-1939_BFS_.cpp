#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int v, e;
int first, second;
//linked list
vector<pair<int, int>> vec[10005];
bool BFS(int m){
    queue<int> q;
    int vis[v+1];
    memset(vis,0,sizeof(vis));
    q.push(first);
    vis[first]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto i : vec[x]){
            int nx = i.first;
            int w = i.second;
            if(w>=m && vis[nx]==0){
                if(nx==second) return true;
                q.push(nx);
                vis[nx]=1;
            }
        }
    }
    return false;
}
int main(){
    cin >> v >> e;
    int maximumweight = 0;
    for(int i =0 ; i < e; i++){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        vec[tmp1].push_back(make_pair(tmp2, tmp3));
        vec[tmp2].push_back(make_pair(tmp1, tmp3));
        maximumweight = max(maximumweight, tmp3);
    }
    cin>>first>>second;
    int l, r;
    l = 0; r = maximumweight;
    int mx = 0;
    while(l <= r){
        int m = (l + r)/2;
        //m represents potential weight.
        //put first in.
        if(BFS(m)){
            mx=max(m,mx);
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    cout << mx;
}