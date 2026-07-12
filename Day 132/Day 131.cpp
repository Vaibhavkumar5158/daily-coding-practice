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
        int64 c, k;
        cin >> n >> c >> k;

        vector<int64> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            if (a[i] > c) break;

            int64 use = min(k, c - a[i]);
            k -= use;
            c += a[i] + use;
        }

        cout << c << '\n';
    }

    return 0;
}