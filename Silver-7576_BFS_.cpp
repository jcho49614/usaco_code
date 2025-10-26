#include <iostream>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

//using a representation of the grid.

int arr[1005][1005];
int visarr[1005][1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<tuple<int, int, int>> q;

int main(){

    memset(arr, 0, sizeof(arr));
    memset(visarr, 0, sizeof(visarr));

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int tmp; cin >> tmp;
            arr[j][i] = tmp;
            //n repeats everysingletime, m represts slwoly.
            //n is column, m is row.
            if(tmp == 1) q.push(make_tuple(j, i, 0));
        }
    }

    //constantly update arr from 0 --> 1
    //use visit array to register already run through versions.

    int maximum_layer = 0;

    while(!q.empty()){
        auto tmp = q.front();
        int a = get<0>(tmp);
        int b = get<1>(tmp);
        int c = get<2>(tmp);
        q.pop();

        //set visit array!
        visarr[a][b] = 1;

        //find new 0s around this one.
        //make those zeroes ones.
        //add to queue.

        for(int i = 0; i< 4; i++){
            if(a + dx[i] < 0 || a + dx[i] >= n || b + dy[i] < 0 || b + dy[i] >= m) continue;
            if(visarr[a+dx[i]][b+dy[i]] != 1 && arr[a+dx[i]][b+dy[i]] == 0){
                q.push(make_tuple(a+dx[i], b+dy[i], c+1));
                maximum_layer = max(maximum_layer, c+1);
                arr[a+dx[i]][b+dy[i]] = 1;
            }
        }
    }
    
    bool solvable = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[j][i] == 0){
                solvable = 0;
                break;
            }
        }
    }

    if(solvable){
        cout << maximum_layer << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}