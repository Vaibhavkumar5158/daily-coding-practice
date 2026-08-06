#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> w(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> w[i];

        // n = 1 can never work
        if (n == 1) {
            cout << "NO\n";
            continue;
        }

        long long low = 0;
        long long high = LLONG_MAX;

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0)
                low = max(low, w[i]);      // even -> left -> w[i] < k
            else
                high = min(high, w[i]);    // odd -> right -> w[i] > k
        }

        if (high - low >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}