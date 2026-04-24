#include <iostream>
#include <tuple>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;
 bool visarr[105][105];
 queue<pair<int,pair<int,int>>> q;

int main(){
    int n, m; cin >> n >> m;
    int layer, mini; cin >> layer >> mini;
    
   

    q.push(make_pair(0,make_pair(0,0))); //firstbucket, secondbucket, layer
    visarr[0][0] = 1;
    //limits: fb n, sb m, layer layer.

    int minimumdiff = __INT32_MAX__;
    int a,b,c;
    while(!q.empty()){
        a = q.front().first;
        b = q.front().second.first;
        c = q.front().second.second;
        q.pop();

        int a1 = a, a2 = a, a3 = a, a4 = a, a5 = a, a6 = a;
        int b1 = b, b2 = b, b3 = b, b4 = b, b5 = b, b6 = b;

        //first discourse: fill bucket a.
        a1 = n;
        if(visarr[a1][b1] != 1 && c < layer)
        {
            q.push(make_pair(a1,make_pair(b1,c+1)));
            minimumdiff = min(minimumdiff, abs(mini - (a1+b1)));
            //////s.insert(a1+ b1);
        }

        //second discourse: fill bucket b.
        b2 = m;
        if(visarr[a2][b2] != 1 && c < layer) {
            q.push(make_pair(a2,make_pair(b2,c+1)));
            minimumdiff = min(minimumdiff, abs(mini - (a2+b2)));
            //////s.insert(a2+b2);
        }
        //third: put contents of bucket b in bucket a.
        int tmp1 = n - a;
        if(tmp1 >= b3){
            b3 = 0;
            a3 += b3;
        }
        else{
            a3 = n;
            b3 -= tmp1;
        }
        if(visarr[a3][b3] != 1 && c < layer) {
            q.push(make_pair(a3,make_pair(b3,c+1)));
            minimumdiff = min(minimumdiff, abs(mini - (a3+b3)));
            ////s.insert(a3+b3);
        }

        //fourth: put contents of bucket a in bucket b;
        int tmp2 = m - b;
        if(tmp2 >= a4){
            a4 = 0;
            b4 += a4;
        }
        else{
            b4 = n;
            a4 -= tmp2;
        }
        if(visarr[a4][b4] != 1 && c < layer) {
            q.push(make_pair(a4,make_pair(b4,c+1)));
            minimumdiff = min(minimumdiff, abs(mini - (a4+b4)));
            //s.insert(a4+b4);
        }

        //fifth: remove contents of bucket a.
        a5 = 0;
        if(visarr[a5][b5] != 1 && c < layer) {
            q.push(make_pair(a5,make_pair(b5,c+1)));
            minimumdiff = min(minimumdiff, abs(mini - (a5+b5)));
            //s.insert(a5+b5);
        }

        //sixth: remove contents of bucket b.
        b6 = 0;
        if(visarr[a6][b6] != 1 && c < layer) {
            q.push(make_pair(a6,make_pair(b6,c+1)));
            minimumdiff = min(minimumdiff, abs(mini - (a6+b6)));
            //s.insert(a6+b6);
        }
    }

    
    // for(auto it = s.begin(); it != s.end(); it++){
    //     int tmp = *it;
    //     if(minimumdiff > abs(mini-tmp)) minimumdiff = abs(mini-tmp);
    // }

    cout << minimumdiff << "\n";
}