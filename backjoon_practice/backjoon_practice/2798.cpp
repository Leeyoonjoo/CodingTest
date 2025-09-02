#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, M;
    cin >> n >> M;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    sort(v.begin(), v.end()); // 오름차순 정렬

    int best = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int sum = v[i] + v[j] + v[k];

                if (sum == M) {           // 딱 맞으면 바로 종료 가능
                    cout << M;
                    return 0;
                }
                if (sum < M) {
                    if (sum > best) 
                        best = sum;
                }
                else {
                    // 정렬되어 있으므로 k를 더 늘리면 합이 더 커짐 → 가지치기
                    break;
                }
            }
        }
    }

    cout << best;
    return 0;
}
