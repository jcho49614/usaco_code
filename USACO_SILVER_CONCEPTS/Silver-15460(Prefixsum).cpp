/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
(Given Code -- Use as Reference)

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[100001];
long long s[100001];
long long m[100001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        s[i] = arr[i] + s[i-1];
    }
    m[n] = arr[n];
    for(int i=n-1;i>0;i--){
        m[i] = min(arr[i],m[i+1]);
    }
    long long msum = 0;
    long long mcnt = 1;
    for(int k=1;k<n-1;k++){
        if((s[n]-s[k]-m[k+1])*mcnt>msum*(n-k-1)){
            msum = (s[n]-s[k]-m[k+1]);
            mcnt = (n-k-1);
        }
    }
    for(int k=1;k<n-1;k++){
        if((s[n]-s[k]-m[k+1])*mcnt==msum*(n-k-1)){
            cout << k << '\n';
        }
    }
}