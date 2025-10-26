#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int arr[100005];

int main(){
    cin >> n >> m;
    int mx=0;
    for(int i =0 ; i< n; i++){
        cin >> arr[i];
        mx=max(mx,arr[i]);
    }

    sort(arr, arr+n);

    int maximum_collection = 0;
    vector<int> v;
    for(int i=1;i<=mx;i++){
        v.clear();
        int tmpcnt = 0;
        for(int j=0;j<n;j++){
            tmpcnt+=arr[j]/i;
            v.push_back(arr[j] % i);
        }
        if(tmpcnt<m/2){
            break;
        }
        if(tmpcnt>=m){
            maximum_collection = max(maximum_collection, i* m /2);
            continue;
        }

        //check if there's remainders and check if there isn't.
        sort(v.begin(), v.end());
        //required baskets is m / 2;
        int requiredbaskets = m / 2;
        int currentbaskets = tmpcnt - (m / 2);
        int noncurrentbaskets = requiredbaskets - currentbaskets;
        int tmpmaximumcollection = currentbaskets * i;
        for (int j =0; j < noncurrentbaskets && j<n; j++){
            tmpmaximumcollection += v[v.size() - 1 - j];
        }

        maximum_collection = max(maximum_collection, tmpmaximumcollection);

    }
    // while(true){
    //     //find the basket numbers!.
    //     int tmpcnt = 0;
    //     for(int i =0 ; i < n; i++){
    //         tmpcnt += (arr[i] / minimumberry);
    //     }
    //     if(tmpcnt >= m){
    //         maximum_collection = minimumberry * m / 2;
    //     }
    //     else{

    //     }
    // }

    cout << maximum_collection << "\n";

}