#include <bits/stdc++.h>
using namespace std;

const long long MOD = 676767677;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long ans = 0;
        int lastGreaterThanOne = -1;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] > 1) {
                ans += a[i];
                lastGreaterThanOne = i;
            }
        }

        bool trailingOnes = false;

        for (int i = lastGreaterThanOne + 1; i < n; i++) {
            if (a[i] == 1) {
                trailingOnes = true;
                break;
            }
        }

        if (trailingOnes) ans++;

        cout << ans % MOD << '\n';
    }

    return 0;
}