#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();

        int totalNon2Non4 = 0;

        for (char c : s) {
            if (c == '1' || c == '3') {
                totalNon2Non4++;
            }
        }

        int twoBefore = 0;
        int non2After = totalNon2Non4;

        int maxKeep = 0;

        // split before first character
        maxKeep = max(maxKeep, twoBefore + non2After);

        for (char c : s) {
            if (c == '2') {
                twoBefore++;
            } else if (c == '1' || c == '3') {
                non2After--;
            }
            // '4' is always deleted, ignore it

            maxKeep = max(maxKeep, twoBefore + non2After);
        }

        cout << n - maxKeep << '\n';
    }

    return 0;
}