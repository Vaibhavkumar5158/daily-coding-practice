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

        vector<long long> aOdd, aEven, bOdd, bEven;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (i % 2 == 0)
                aOdd.push_back(x);
            else
                aEven.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (i % 2 == 0)
                bOdd.push_back(x);
            else
                bEven.push_back(x);
        }

        sort(aOdd.begin(), aOdd.end());
        sort(aEven.begin(), aEven.end());
        sort(bOdd.begin(), bOdd.end());
        sort(bEven.begin(), bEven.end());

        if (aOdd == bOdd && aEven == bEven)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}