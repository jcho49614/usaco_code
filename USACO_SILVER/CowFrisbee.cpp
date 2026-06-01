#include <iostream>
#include <stack>
#include <map>
using namespace std;
long long arr[400005];
stack<long long> s;
map<long long, long long> location;

int main(){
    long long n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //going from start to finish, using stacks to work it properly.


    s.push(arr[0]);
    location[arr[0]] = 0;

    long long distancecount = 0;

    for(int i = 1 ; i < n; i++){
        //get the value from the array, add distance between it, (pop if smaller), and push.
        long long tmp = arr[i];
        //first add it to the ones right before.

        long long tmpn = i;

        while(!s.empty() && s.top() < tmp){
        	long long distance = (i - location[s.top()] + 1);
            distancecount += distance;
            s.pop();
        }

        if(!s.empty() && s.top() > tmp){
            long long distance = (i - location[s.top()] + 1);
            distancecount += distance;
        }

        location[arr[i]] = i;
        s.push(arr[i]);
    }

    cout << distancecount << "\n";
}