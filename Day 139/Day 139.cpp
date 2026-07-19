#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int sum = 0;
        int mx = -100;

        for (int i = 0; i < 7; i++) {
            int x;
            cin >> x;
            sum += x;
            mx = max(mx, x);
        }

        cout << 2 * mx - sum << '\n';
    }

    return 0;
}