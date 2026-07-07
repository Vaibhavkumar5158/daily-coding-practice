#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> b(n);

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(b.begin(), b.end(), greater<long long>());

        vector<long long> a;
        a.push_back(b[0]);
        a.push_back(b[1]);

        while ((int)a.size() < n) {
            long long nxt = a[a.size() - 2] % a[a.size() - 1];

            if (nxt == 0) break;

            a.push_back(nxt);
        }

        if ((int)a.size() != n) {
            cout << -1 << '\n';
            continue;
        }

        vector<long long> c = a;
        sort(c.begin(), c.end(), greater<long long>());

        if (c == b) {
            cout << a[0] << " " << a[1] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}