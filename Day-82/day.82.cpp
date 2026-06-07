#include <bits/stdc++.h>
using namespace std;

bool check(string &s, char first) {
    int n = s.size();

    int l = -1, r = -1;

    for (int i = 0; i < n; i++) {
        char expected;

        if (i % 2 == 0) expected = first;
        else expected = (first == 'a' ? 'b' : 'a');

        if (s[i] != expected) {
            if (l == -1) l = i;
            r = i;
        }
    }

    // already alternating
    if (l == -1) return true;

    // all mismatched positions must be continuous
    for (int i = l; i <= r; i++) {
        char expected;

        if (i % 2 == 0) expected = first;
        else expected = (first == 'a' ? 'b' : 'a');

        if (s[i] == expected) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        if (check(s, 'a') || check(s, 'b')) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}