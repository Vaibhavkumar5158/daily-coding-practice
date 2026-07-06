#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;
        int mn = a[0];

        for (int i = 0; i < n; i++) {
            mn = min(mn, a[i]);
            ans += mn;
        }

        cout << ans << '\n';
    }

    return 0;
}