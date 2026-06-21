#include <bits/stdc++.h>
using namespace std;

bool adjust(int &L, int &R, int parity) {
    if ((L & 1) != parity) L++;
    if ((R & 1) != parity) R--;
    return L <= R;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int s = 0;      // common balance: "((" gives +1, "))" gives -1
        int L = 0, R = 0; 
        int parity = 0;

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (a[i] == '(' && b[i] == '(') {
                s++;
            } 
            else if (a[i] == ')' && b[i] == ')') {
                s--;
            } 
            else {
                // mixed pair: one string gets '(' and other gets ')'
                L--;
                R++;
                parity ^= 1;
            }

            if (s < 0) {
                ok = false;
                break;
            }

            int low = -s;
            int high = s;

            L = max(L, low);
            R = min(R, high);

            if (!adjust(L, R, parity)) {
                ok = false;
                break;
            }
        }

        if (s != 0 || parity != 0 || !(L <= 0 && 0 <= R)) {
            ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}