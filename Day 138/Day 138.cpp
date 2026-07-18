#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int64> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        for (int start = 0; start < n; start++) {
            int64 cur = 0;
            int64 ans = 0;

            int edge = start;
            int v = (start + 1) % n;

            for (int cnt = 0; cnt < n - 1; cnt++) {
                cur = max(cur, h[edge]);
                ans += cur;

                edge = v;
                v = (v + 1) % n;
            }

            cout << ans << " ";
        }
        cout << '\n';
    }

    return 0;
}