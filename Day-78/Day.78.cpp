#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sum = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            sum += a[i];

            long long avg = sum / (i + 1);
            ans = min(ans, avg);

            cout << ans << " ";
        }

        cout << '\n';
    }

    return 0;
}