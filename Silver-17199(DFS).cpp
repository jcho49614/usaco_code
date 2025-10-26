#include <iostream>
using namespace std;

int n;
int arr[105][105];
//visit array
int vis[105];

/*

since I set it the opposite (instead of 1 -- > 2, 2 --> 1)
i can make a set for both visit arrays, 


*/

void dfs(int x){
    //dfs through the things.
    vis[x] = 1;
    //1-100

    for(int i =1 ; i < 105; i++){
        if(arr[x][i] == 1 && vis[i]==0) dfs(i);
    }

}

int solution = -1;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i =0 ; i < n-1; i++){
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        arr[tmp2][tmp1] = 1;
        //single direction adjunct matrix
    }

    for(int i =0; i < n; i++){
        for(int j=0; j < 105; j++){
            vis[j] = 0;
        }

        dfs(i+1);

        bool check = true;

        for(int j = 1; j <= n; j++){
            if(vis[j] == 0) check = false;
        }

        if(!check) continue;
        else {solution = i+1; break;}
    }

    cout << solution << "\n";
}