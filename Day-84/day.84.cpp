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

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> ans;
        int flip = 0; // 0 = normal, 1 = sign flipped

        for (int i = n; i >= 1; i--) {
            long long curr = a[i];

            if (flip) curr = -curr;

            if (curr > 0) {
                ans.push_back(i);
                flip ^= 1;
            }
        }

        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}