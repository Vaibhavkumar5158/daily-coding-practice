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

        vector<vector<int>> children(n + 1);

        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            children[p].push_back(i);
        }

        vector<long long> height(n + 1, 0);
        long long ans = n; // every single vertex guild is unique

        for (int v = n; v >= 1; v--) {
            long long mx1 = 0, mx2 = 0;

            for (int child : children[v]) {
                long long len = height[child] + 1;

                if (len > mx1) {
                    mx2 = mx1;
                    mx1 = len;
                } else if (len > mx2) {
                    mx2 = len;
                }
            }

            height[v] = mx1;

            // mx2 = number of non-singleton guilds whose LCA is v
            ans += mx2;
        }

        cout << ans << '\n';
    }

    return 0;
}