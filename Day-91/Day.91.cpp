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

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x == 0) cnt0++;
            else if (x == 1) cnt1++;
            else cnt2++;
        }

        int ans = cnt0;

        int pairs = min(cnt1, cnt2);
        ans += pairs;

        cnt1 -= pairs;
        cnt2 -= pairs;

        ans += cnt1 / 3;
        ans += cnt2 / 3;

        cout << ans << '\n';
    }

    return 0;
}