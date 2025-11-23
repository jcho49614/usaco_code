#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[100005];
int visarr[100005];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i =0; i < n-1; i++)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    //linked list.

    queue<int> q;
    q.push(1);


    int cnt = 0;

    while(!q.empty()){
        //the first value of q is the parent.
        //we need to take out the parent, and find its children
        //after we found its children, we add them to a tempcnt
        int a = q.front();
        q.pop();
        visarr[a] = 1;
        int totalcnt = 0;
        int tempcnt = 0;
        int b = 1;
       

        int slavecount = 0;

        for(int i =0 ; i < v[a].size(); i++){
            if(visarr[v[a][i]]==0) slavecount++;
            if (visarr[v[a][i]] == 0) q.push(v[a][i]);
        }

         while(b <= slavecount){
            b *= 2;
            tempcnt++;
        }

        totalcnt = tempcnt + slavecount;
        cnt += totalcnt;
    }

    cout << cnt << "\n";
}