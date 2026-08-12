#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // p = [2, 3, 4, ..., n, 1]
        for (int i = 2; i <= n; i++) {
            cout << i << " ";
        }

        cout << 1 << "\n";
    }

    return 0;
}