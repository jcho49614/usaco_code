#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> v[100005];
int vmax[100005];
int vmin[100005];





int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    
    for(int i =1 ; i<= n; i++){
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a,b);
    }

    sort(v+1, v+n+1);
    
    


    vmin[0] = INT32_MAX;

    for(int i =1; i < n+1; i++){
        if(v[i].second < vmin[i-1]) vmin[i] = v[i].second; //vmin.push_back(v[i].second); 
        else vmin[i] = vmin[i-1];    // vmin.push_back(vmin[vmin.size()-1]);
    }

    vmax[n+1] = INT32_MIN; // max.push_back(0x7FFFFFFF*-1);

    for(int i= n; i >= 1; i--){
        if(v[i].second > vmax[i+1]) vmax[i] = v[i].second;//     vmax.push_back(v[i].second);
        else vmax[i] = vmax[i+1];//     vmax.push_back(vmax[vmax.size()-1]);
    }

    



    int cnt = 0;

    for(int i = 1; i < n+1; i++){
        //if bottom is larger than top then able to be removed!
        if(vmin[i] > vmax[i+1]) cnt++;
    }

    cout << cnt << "\n";




    //      2 2 1 1 1 0 0   0 -1 -inf
    // +inf 1 1 0 0 0 -1 -1- -1 

}