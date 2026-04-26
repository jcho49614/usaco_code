#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

//December 2020, Silver #2

using namespace std;

int arr[2505][2505];
int prefix[2505][2505];

int xcoords[2505];
int ycoords[2505];

int prefixsum(int x1, int y1, int x2, int y2){
    return prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
}

bool cmpY(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }
    
    //now create a noraml arr. I need to 1 index it.
    sort(points.begin(), points.end(), cmpY);
    for(int i = 0; i < n; i++) points[i].second = i + 1;
    sort(points.begin(), points.end());
    for(int i = 0; i < n; i++) points[i].first = i + 1;

    //now time to plug in the values of the array into the main array
    for(int i = 0; i < n; i++){
        arr[points[i].first][points[i].second] = 1;
    }
    
    //now create prefix arr
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefix[i][j] = arr[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    //done with compressoin
    //now time for finding all possible ranges that I could think of.
    long long totalcnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int x1 = points[i].first;
            int x2 = points[j].first;
            int y1 = points[i].second;
            int y2 = points[j].second;

            int y_min = min(y1, y2);
            int y_max = max(y1, y2);

            long long tmp1 = prefixsum(x1, y_max, x2, n);
            long long tmp2 = prefixsum(x1, 1, x2, y_min);
            totalcnt += tmp1 * tmp2;
        }
    }

    totalcnt += (n + 1);

    cout << totalcnt << "\n";
    return 0;
}