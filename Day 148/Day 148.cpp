
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

        int blocks = n - k;

        int zero = n / 2;
        int one = n - zero;

        bool ok = false;
        string ans;

        for (int start = 0; start < 2 && !ok; start++) {

            int z = zero, o = one;

            vector<pair<char, int>> seg;

            bool valid = true;

            // create alternating blocks of length 1
            for (int i = 0; i < blocks; i++) {
                char c = ((i + start) % 2 == 0) ? '0' : '1';

                if (c == '0') {
                    if (z == 0) {
                        valid = false;
                        break;
                    }
                    z--;
                } else {
                    if (o == 0) {
                        valid = false;
                        break;
                    }
                    o--;
                }

                seg.push_back({c, 1});
            }

            if (!valid) continue;

            // extend first block
            if (seg[0].first == '0') {
                if (z < k) continue;
                seg[0].second += k;
                z -= k;
            } else {
                if (o < k) continue;
                seg[0].second += k;
                o -= k;
            }

            // distribute remaining characters
            for (int i = 0; i < blocks; i++) {
                if (seg[i].first == '0' && z > 0) {
                    seg[i].second++;
                    z--;
                } else if (seg[i].first == '1' && o > 0) {
                    seg[i].second++;
                    o--;
                }
            }

            if (z == 0 && o == 0) {
                ans.clear();
                for (auto [c, len] : seg)
                    ans.append(len, c);
                ok = true;
            }
        }

        if (ok)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}