#include <iostream>
#include <set>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	
	multiset<int> s;

	int n; cin >> n;
	for(int i = 0 ; i < n; i++){
		int tmp; cin >> tmp;
		if(tmp == 0){
			if(s.empty()){
				cout << 0 << "\n";
			}
			else{
				cout << *s.begin() << "\n";
				s.erase(s.begin());
			}
		}
		else{
			s.insert(tmp);
		}
	}
}