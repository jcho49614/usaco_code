#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//linked list

vector<int> v[100005];

int main(){
    int n; cin >> n;
    for(int i =0 ; i < n; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    //Comon root is 1.

    queue<int> q; 
    q.push(1);

    int totalcount = n -1; //totalcount, we nwill add the others to it.
    
    while(!q.empty()){
        int a = q.front();
        q.pop();
        //now there is the index 1. we popped that, and find the connecting values. 1 represents the initial vertex. Now we need to find the connecting values.

        int tmpcnt = 0;
        for(int i : v[a]){
            //we need to count the amount of cows required.
            tmpcnt++;
        }

        if(tmpcnt % 2 == 0){
            while (tmpcnt != 1){
                totalcount++;
                tmpcnt /= 2;
            }
        }
        else{
            while (tmpcnt !=1){
                totalcount++;
                tmpcnt /= 2;
            }
            totalcount++;
        }

    }

    cout << totalcount << "\n";


}