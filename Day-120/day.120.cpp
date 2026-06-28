#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> prefOpen(n + 1, 0);
        vector<int> suffClose(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefOpen[i + 1] = prefOpen[i] + (s[i] == '(');
        }

        for (int i = n - 1; i >= 0; i--) {
            suffClose[i] = suffClose[i + 1] + (s[i] == ')');
        }

        int best = n + 1;
        int split = 0;

        for (int i = 0; i <= n; i++) {
            int deletions = prefOpen[i] + suffClose[i];

            if (deletions < best) {
                best = deletions;
                split = i;
            }
        }

        string ans(n, '0');
        int canDelete = min(k, best);

        for (int i = 0; i < n && canDelete > 0; i++) {
            if (i < split && s[i] == '(') {
                ans[i] = '1';
                canDelete--;
            } 
            else if (i >= split && s[i] == ')') {
                ans[i] = '1';
                canDelete--;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}