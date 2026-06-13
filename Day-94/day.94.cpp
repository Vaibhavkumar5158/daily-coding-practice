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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxScore = 100 * n;

        vector<int> dp(maxScore + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            vector<int> ndp(maxScore + 1, 0);

            int step = 100 / a[i];

            for (int score = 0; score <= maxScore; score++) {
                if (dp[score]) {
                    for (int x = 0; x <= a[i]; x++) {
                        int newScore = score + x * step;

                        if (newScore <= maxScore) {
                            ndp[newScore] = 1;
                        }
                    }
                }
            }

            dp = ndp;
        }

        bool ok = true;

        for (int score = 0; score <= maxScore; score++) {
            if (!dp[score]) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}