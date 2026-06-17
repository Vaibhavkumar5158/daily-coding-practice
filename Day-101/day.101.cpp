#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n + 1);
        ll total = 0;

        vector<ll> odd, even;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            total += a[i];

            if (i % 2) odd.push_back(a[i]);
            else even.push_back(a[i]);
        }

        int oddMarks = 0, evenMarks = 0;

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;

            if (x % 2) oddMarks++;
            else evenMarks++;
        }

        auto bestMarkedSum = [&](vector<ll>& v, int cnt) {
            if (cnt == 0) return 0LL;

            sort(v.rbegin(), v.rend());

            ll sum = 0;
            ll best = LLONG_MIN;

            int limit = min((int)v.size(), cnt);

            for (int i = 0; i < limit; i++) {
                sum += v[i];
                best = max(best, sum);
            }

            return best;
        };

        ll markedSum = 0;
        markedSum += bestMarkedSum(odd, oddMarks);
        markedSum += bestMarkedSum(even, evenMarks);

        cout << total - markedSum << '\n';
    }

    return 0;
}