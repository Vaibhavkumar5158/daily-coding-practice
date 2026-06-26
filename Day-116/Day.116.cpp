#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n;
        cin >> n;

        string s;
        cin >> s;

        long long total = n * (n + 1) / 2;

        // Count substrings whose value sum % 3 == 0
        // 0 -> 1
        // 1 -> 2
        vector<long long> freq(3, 0);
        freq[0] = 1;

        int pref = 0;

        for (char c : s) {
            if (c == '0') pref = (pref + 1) % 3;
            else pref = (pref + 2) % 3;

            freq[pref]++;
        }

        long long badModulo = 0;
        for (int i = 0; i < 3; i++) {
            badModulo += freq[i] * (freq[i] - 1) / 2;
        }

        long long ans = total - badModulo;

        // Remove odd-length alternating substrings of length >= 3
        long long badAlternating = 0;

        for (int i = 0; i < n; ) {
            int j = i;

            while (j + 1 < n && s[j + 1] != s[j]) {
                j++;
            }

            long long len = j - i + 1;

            badAlternating += (len - 1) * (len - 1) / 4;

            i = j + 1;
        }

        ans -= badAlternating;

        cout << ans << '\n';
    }

    return 0;
}