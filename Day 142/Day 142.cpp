#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;

        int onlyRow = 0, onlyCol = 0, both = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            bool r = (x <= h);
            bool c = (x <= l);

            if (r && c)
                both++;
            else if (r)
                onlyRow++;
            else if (c)
                onlyCol++;
        }

        int ans = 0;

        // Pair fixed row-only with fixed col-only
        int x = min(onlyRow, onlyCol);
        ans += x;
        onlyRow -= x;
        onlyCol -= x;

        // Use "both" to complete remaining row-only
        x = min(onlyRow, both);
        ans += x;
        both -= x;

        // Use "both" to complete remaining col-only
        x = min(onlyCol, both);
        ans += x;
        both -= x;

        // Remaining "both" can pair among themselves
        ans += both / 2;

        cout << ans << '\n';
    }

    return 0;
}