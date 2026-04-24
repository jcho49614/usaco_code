#include <iostream>

using namespace std;

int arr[100001];
int main(){
  int n,k;
  long long sum = 0;
  cin >> n;
  long long ans = 0;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cin >> k;
  int st=0,en=0;
  while(1){
    if(en==n){
      if(sum>k){
        ans+=1;
        sum-=arr[st];
        st+=1;
      }
      else{
        break;
      }
      continue;
    }
   
    if(sum<=k){
      sum+=arr[en];
      en+=1;
    }
    else{
      ans+=n-en+1;
      sum-=arr[st];
      st+=1;
    }
  }
 
  cout << ans;
}