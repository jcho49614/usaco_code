#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[100005];
vector<pair<int, pair<int, int>>> arr2;
// int arr3[100005][100005];
vector<int> arr3[100005];
int arr4[100005];
int vis[100005];

void dfs(int x, int set){
    //x is the input, set is the thing we have to put it on.
    vis[x] = 1;
    arr4[x] = set;
    // for(int i =1 ; i <= m; i++){
    //     if(arr3[x][i] == 1 && vis[i] == 0){
    //         dfs(i, set);
    //     }
    // }

    for(auto it : arr3[x]){
        if(vis[it] == 0) dfs(it,set);
    }


}

bool dfsprocess(int h){
/*
step 1: find possible conditions, push to vector
step 2: memset the visarr
step 3: dfs it and put in the numbers. use adjunct matrix!
step 4: see if you can go through grouping.n
step 5: return true if you can, return false if you can't.
*/
    //i should make the adj matrix

    for(int i = 0; i < m; i++){
        if(arr2[i].first >= h){
            //make the adj matrix from second.first and second.second
            // arr3[arr2[i].second.first][arr2[i].second.second] = 1;
            // arr3[arr2[i].second.second][arr2[i].second.first] = 1;

            arr3[arr2[i].second.first].push_back(arr2[i].second.second);
            arr3[arr2[i].second.second].push_back(arr2[i].second.first);
        }
    }
    int intcnt = 0;
    for(int i =1; i <= n; i++){
        if(vis[i] != 1){
            dfs(i, intcnt);
            intcnt++;
        }
    }

    //finished grouping.
    //compare and contrast with original vs normal!
    bool check = true;
    for(int i =0 ; i < n; i++){
        //i+1 vs arr[i]
        if(arr4[arr[i]] != arr4[i+1]) {
            check = false;
            break;
        }
    }

    if(check) return true;
    else return false;
}

int main(){
    cin >> n >> m;

    for(int i =0 ; i < n; i++){
        cin >> arr[i];
    }

    int maximum = 0;

    for(int i =0 ;i < m; i++){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        arr2.push_back(make_pair(tmp3, make_pair(tmp2, tmp3)));
        maximum = max(maximum, tmp3);
    }

    sort(arr2.begin(), arr2.end());

    //binary search for size of wormhole.

    int l, h; l = 1; h = maximum;

    int mid;
    int ans=maximum+1;
    
    while(l <= h){
        mid = (l+h)/2;
        //mid is the squishing threshold.
        //run dfs, sorting!
        /*
        everything will be in dfsprocess.
        */
        bool status = dfsprocess(mid);
        if(!status){
            //middle check?
            
            h = mid - 1;
        }
        else{
            ans=min(ans,mid);
            l = mid + 1;
        }
    }
    if(ans==maximum+1) cout << -1;
    else cout << ans << "\n";

}