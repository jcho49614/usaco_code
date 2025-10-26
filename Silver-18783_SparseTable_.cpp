#include <bits/stdc++.h>

using namespace std;

int N, M, K, prv, cur = 1;
int arr[100001];
int sparse[2][100001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
      arr[i] = i;
    }
    while (M--) {
        int s, t;
        cin >> s >> t;
        --s;
        reverse(arr + s, arr + t);
    }
    for(int i=0;i<N;i++){
      sparse[0][i] = arr[i];
    }
    --K;

    while (K) {
        if (K & 1) {
            for(int i=0;i<N;i++){
                arr[i] = sparse[prv][arr[i]];
            }
        }
        for(int i=0;i<N;i++) {
            sparse[cur][i] = sparse[prv][sparse[prv][i]];
        }
        swap(cur, prv);
        K >>= 1;
    }
    for(int i=0;i<N;i++) {
        cout << arr[i] + 1 << '\n';
    }
    return 0;
}
