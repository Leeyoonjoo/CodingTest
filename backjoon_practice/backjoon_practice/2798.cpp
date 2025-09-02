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

    sort(v.begin(), v.end()); // �������� ����

    int best = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int sum = v[i] + v[j] + v[k];

                if (sum == M) {           // �� ������ �ٷ� ���� ����
                    cout << M;
                    return 0;
                }
                if (sum < M) {
                    if (sum > best) 
                        best = sum;
                }
                else {
                    // ���ĵǾ� �����Ƿ� k�� �� �ø��� ���� �� Ŀ�� �� ����ġ��
                    break;
                }
            }
        }
    }

    cout << best;
    return 0;
}
