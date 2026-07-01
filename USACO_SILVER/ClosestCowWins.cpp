#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int grassypatches[1000000005];		//this is for the flavor
int identifier[1000000005];			//1 is for grassy patch, 2 is for Nhoj's cows
int ncl[200005];
vector<pair<int, long long>> potentialjc;	//first integer is amount of cows, second integer is how much FLAVOR

//only the tastiness total sum should be long long

int main(){
	int k, m, n;
	cin >> k >> m >> n;
	
	for(int i =0 ; i < k; i++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		grassypatches[tmp1] = tmp2;
		identifier[tmp1] = 1;
	}

	for(int i = 0; i < m; i++){
		int tmp1; cin >> tmp1;
		identifier[tmp1] = 2;
		ncl[i] = tmp1;
	}

	//STAGE 1: BEFORE NHOJ

	int count = 0;
	long long flavourcount = 0;
	while(true){
		if(identifier[count] == 2) break;
		else if(identifier[count] == 0) {count++; continue;}
		else {flavourcount += grassypatches[count]; count++;}
	}
	potentialjc.push_back(make_pair(1, flavourcount));

	//STAGE 2: DURING NHOJ.
	/*
	Two stages: Inbetween every NHOJ you can either get all
	values with 1 cow or 2 cows.

	Use the Sliding Window principle.

	*/

	int sn = 0;
	int en = 1;		//these are the indexes for nhoj cows.

	while(en < m){
		//i need to subtract ALL VALUES by nhoj[startingnhoj] so that I can find the middle easier.
		int firstcow = 0;
		int secondcow = ncl[en] - ncl[sn];
		vector<int> gpw;
		vector<int> gpwvalues;
		//all the values inside I need to make a vector for.
		for(int i = ncl[sn] + 1; i <ncl[en]; i++) { 
			if(identifier[i] == 1) {gpw.push_back(i); gpwvalues.push_back(grassypatches[i]);}
		}

		cout << firstcow << ' ' << secondcow << endl;
		for(int i =0 ; i < gpw.size(); i++){
			cout << gpw[i] << ' ' << gpwvalues[i] << ' ';
		}
		cout << "\n\n";


		sn++; en++;
	}

}