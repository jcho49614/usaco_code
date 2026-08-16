#include <bits/stdc++.h>
using namespace std;

int K, M, N;

struct Grass {
    long long p, t; // 위치(position), 맛(tastiness)
};
Grass grass[200005];
long long nhoj[200005];

// 잔디를 위치 순으로 오름차순 정렬
bool cmpGrass(Grass a, Grass b) {
    return a.p < b.p;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> K >> M >> N;
    for (int i = 0; i < K; i++) {
        cin >> grass[i].p >> grass[i].t;
    }
    for (int i = 0; i < M; i++) {
        cin >> nhoj[i];
    }

    sort(grass, grass + K, cmpGrass);
    sort(nhoj, nhoj + M);

    vector<long long> values; // 소 1마리를 투자할 때마다 얻을 수 있는 이득들
    int g_idx = 0;

    // 1. 노지의 첫 번째 소보다 '왼쪽' 구역 (1마리로 전체 독식)
    long long left_sum = 0;
    while (g_idx < K && grass[g_idx].p < nhoj[0]) {
        left_sum += grass[g_idx].t;
        g_idx++;
    }
    values.push_back(left_sum);

    // 2. 노지의 소들 '사이' 구역 (투 포인터 슬라이딩 윈도우)
    for (int i = 0; i < M - 1; i++) {
        long long A = nhoj[i];
        long long B = nhoj[i + 1];

        long long total_sum = 0;
        int start_idx = g_idx;
        while (g_idx < K && grass[g_idx].p < B) {
            total_sum += grass[g_idx].t;
            g_idx++;
        }

        long long max_window = 0;
        long long current_window = 0;
        int L = start_idx;
        
        // R을 늘려가며 윈도우를 확장
        for (int R = start_idx; R < g_idx; R++) {
            current_window += grass[R].t;
            
            // 윈도우의 길이가 (B - A) / 2 '이상'이 되면 성립하지 않으므로 L을 당겨줌
            // 소수점 오차를 막기 위해 양변에 2를 곱해서 정수 비교: (거리) * 2 >= (B - A)
            while ((grass[R].p - grass[L].p) * 2 >= (B - A)) {
                current_window -= grass[L].t;
                L++;
            }
            max_window = max(max_window, current_window);
        }

        // 1마리 투자했을 때 이득
        values.push_back(max_window);
        // 2마리째 투자했을 때 '추가로' 얻는 이득
        values.push_back(total_sum - max_window); 
    }

    // 3. 노지의 마지막 소보다 '오른쪽' 구역 (1마리로 전체 독식)
    long long right_sum = 0;
    while (g_idx < K) {
        right_sum += grass[g_idx].t;
        g_idx++;
    }
    values.push_back(right_sum);

    // 4. 모든 가능한 이득을 내림차순 정렬하여 가장 큰 N개만 뽑아먹기
    sort(values.begin(), values.end(), greater<long long>());

    long long ans = 0;
    int take = min((int)values.size(), N); // 만약 N이 values.size()보다 클 수도 있으므로 안전장치
    for (int i = 0; i < take; i++) {
        ans += values[i];
    }

    cout << ans << "\n";

    return 0;
}