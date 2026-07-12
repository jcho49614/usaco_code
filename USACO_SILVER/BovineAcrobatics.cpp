#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
//use a pair vector to keep track of cows.
vector<pair<int, int>> cows;
// int findcowamount(queue<pair<int,int>> tmpq, int count){
// 	if(tmpq.empty()) return count;
// 	else{
// 		//find the value of top
// 		int tmp = tmpq.front().second + count;
// 		tmpq.pop();
// 		return findcowamount(tmpq, tmp);
// 	}
// }
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	//n represents n distinct weights, m towers, k distance between variables.
	for(int i =0; i < n; i++){
		int a, b; cin >> a >> b;
		cows.push_back(make_pair(a, b));
	}
	//starting _from top to bottom, sort with greater<>()
	sort(cows.begin(), cows.end(), greater<>());
	long long totalcowsinvolved = 0;
	queue<pair<int, int>> mainqueue;
	long long currentm = m;
	for(int i = 0; i < n; i++){
		//slowly go through the values of the vector.
		//STAGE 1: JUST FIND IF THERE ARE THINGS that contrast with the current set.
		while(!mainqueue.empty()){
			pair<int, int> tmpp = mainqueue.front();
			if(tmpp.first - k < cows[i].first) break;
			else{ currentm += tmpp.second; mainqueue.pop(); }
		}
		//STAGE 2: FIND THE AMOUNT OF COWS CURRENTLY IN THERE.
		// int tmp = findcowamount(mainqueue, 0);
		//now we have the cow amount. Then we can push whatever value there is.
		if(currentm != 0){
			long long tmp2 = currentm;
			if(cows[i].second >= tmp2) {
				mainqueue.push(make_pair(cows[i].first, tmp2));
				totalcowsinvolved += tmp2;
				currentm -= tmp2;
			}
			else {
				mainqueue.push(make_pair(cows[i].first, cows[i].second));
				totalcowsinvolved += cows[i].second;
				currentm -= cows[i].second;
			}
		}
	}
	cout << totalcowsinvolved << "\n";
}