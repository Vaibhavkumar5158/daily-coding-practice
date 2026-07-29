#include <bits/stdc++.h>
using namespace std;

int uglyCount(const vector<int>& a) {
    int mx = 0;
    int cnt = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (mx == i + 1) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<int> ans = p;
        int best = uglyCount(p);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(p[i], p[j]);

                int cur = uglyCount(p);

                if (cur < best) {
                    best = cur;
                    ans = p;
                }

                swap(p[i], p[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}