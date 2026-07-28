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

        vector<int> cnt(101, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }

        const int MAX = 20000;
        vector<int> dp(MAX + 1, 0);
        dp[0] = 1;

        vector<int> ans;
        bool ok = true;

        for (int step = 0; step < n; step++) {
            int pick = -1;

            for (int v = 1; v <= 100; v++) {
                if (cnt[v] && !dp[v]) {
                    pick = v;
                    break;
                }
            }

            if (pick == -1) {
                ok = false;
                break;
            }

            ans.push_back(pick);
            cnt[pick]--;

            for (int s = MAX - pick; s >= 0; s--) {
                if (dp[s]) dp[s + pick] = 1;
            }
        }

        if (!ok) {
            cout << -1 << "\n";
        } else {
            for (int x : ans)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}