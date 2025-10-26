#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int v, e;
vector<int> vect[20005];
int visarr[20005];

void dfs(int now, int prev){
    if(prev == 2) visarr[now] = 1;
    else visarr[now] = 2;

    for(int x : vect[now]){
        if(visarr[x] == 0) dfs(x, visarr[now]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcase; cin >> testcase;
    for(int a = 0; a < testcase; a++){
        for(int i=0;i<20005;i++){
            vect[i].clear();
        }
        memset(visarr, 0, sizeof(visarr));

        cin >> v >> e; //v is vertex, e is edge;
        for(int i = 0; i < e; i++){
            int tmp1, tmp2; cin >> tmp1 >> tmp2;
            vect[tmp1].push_back(tmp2);
            vect[tmp2].push_back(tmp1);
        }

        for(int i = 1; i <= v; i++){
            if(visarr[i] == 0) dfs(i, 2);
        }

        bool check = false;
        for(int i = 1; i <= v; i++){
            for(int j : vect[i]){
                if(visarr[i] == visarr[j]) {
                    check = true; 
                    break;
                }
            }
            if(check) break;
        }

        if(check) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}








// #include <iostream>
// #include <cstring>
// using namespace std;

// int v, e; //vertexes, edges. inputted in this order.
// int arr[20005][20005]; // array for adjunct matrix, buffer
// int visarr[20005]; //visarr --> 0 is not set, 1 is red, 2 is blue.
// //start from R, go B, R, B, R, B, etc. add prev on dfs to check the next move.
// //backtracking will get back the values.
// //testing should consist of for values. 

// void dfs(int now, int prev){
//     if (prev == 2) visarr[now] = 1;
//     else visarr[now] = 2;

//     for(int i = 1; i <= v; i++){
//         if(arr[now][i] == 1 && visarr[i]==0) dfs(i, visarr[now]);
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int testcase; cin >> testcase;
//     for(int a =0 ; a < testcase; a++){
//         memset(arr, 0, sizeof(arr));
//         memset(visarr, 0, sizeof(visarr));
//         cin >> v >> e;
//         //#vertex = maxnum
//         for(int i = 0; i < e; i++){
//             int tmp1, tmp2; cin >> tmp1 >> tmp2;
//             arr[tmp1][tmp2] = 1;
//             arr[tmp2][tmp1] = 1;
//         }

//         for(int i =0 ; i < v; i++){
//             if(visarr[i+1] == 0){     
//                 dfs(i+1, 2); //dfs structure: vertexnumber/previousvertexassignment
//             }
//         }

//         //checking!
//         bool right = true;
//         for(int i = 1; i <= v; i++){
//             for(int j = 1; j <= v; j++){
//                 if(arr[i][j] == 1){
//                     if(visarr[i] == visarr[j]) right = false; break;
//                 }
//             }
//             if(right==false) break;
//         }

//         if(right) cout << "YES" << "\n";
//         else cout << "NO" << "\n";
//     } 
// }