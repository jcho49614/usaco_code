#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int z;
    cin >> z;
    for(int q =0 ; q < z; q++){
        multiset<int> ms;
        int n; cin >> n;
        int arr[n+5];

        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp; arr[i] = tmp;
            ms.insert(tmp);
        }
        //we need to find the absolute value of the difference!

        //size is n
        for(int i = 0; i < n - 1; i++){
            for(int j = i+1; j < n; j++){
                //two values, i, and j
                ms.insert(abs(arr[i] - arr[j]));
            }
        }

        int totalsetcount = 0;

        for(auto it1 = ms.begin(); it1 != ms.end(); it1++){
            for(auto it2 = ms.begin(); it2 != ms.end(); it2++){
                for(auto it3 = ms.begin(); it3 != ms.end(); it3++){
                    if(it1 != it2 && it1 != it3 && it2 != it3){
                        if(*it1 <= *it2 && *it2 <= *it3){
                            //make a set.
                            multiset<int> tmpms;
                            tmpms.insert(*it1); tmpms.insert(*it2); tmpms.insert(*it3); tmpms.insert(*it1+*it2); tmpms.insert(*it1+*it3); tmpms.insert(*it2+*it3); tmpms.insert(*it1+*it2+*it3);

                            bool check = true;
                            for(int i = 0; i < n; i++){
                                if(tmpms.find(arr[i]) == tmpms.end()){
                                    check = false;
                                    break;
                                }
                            }
                            if(check == true){
                                totalsetcount++;
                            }
                            tmpms.clear();
                        }
                    }
                }
            }
        }

        cout << totalsetcount << "\n";
    }
}