#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    //minimum is n, maximum is 2 * n.
    int minimum = n; int maximum = n * 2;

    int solution;
    int tmp;
    int middle;
    while (minimum <= maximum){
        middle = (minimum/2 + maximum/2);
        tmp = middle - middle / 5 - middle / 3 + middle / 15;
        if(tmp > n) maximum = middle - 1;
        else if(tmp < n) minimum = middle+1;
        else{
            solution = middle;
            break;
        }
    }

   while(solution % 5 == 0 || solution % 3 == 0){
    solution--;
   }
   cout << solution;
}