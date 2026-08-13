#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    while (t--) {

        int n;
        cin >> n;

        while (true) {

            vector<int> ans(4 * n, 0);

            // All currently empty positions
            vector<int> empty(4 * n);

            iota(empty.begin(), empty.end(), 0);

            bool possible = true;

            for (int x = 1; x <= n; x++) {

                bool found = false;

                // Try many random choices
                for (int attempt = 0; attempt < 1000; attempt++) {

                    shuffle(empty.begin(), empty.end(), rng);

                    vector<int> pos = {
                        empty[0],
                        empty[1],
                        empty[2],
                        empty[3]
                    };

                    sort(pos.begin(), pos.end());

                    int d1 = pos[1] - pos[0];
                    int d2 = pos[2] - pos[1];
                    int d3 = pos[3] - pos[2];

                    // All three distances must be different
                    if (d1 != d2 &&
                        d2 != d3 &&
                        d1 != d3) {

                        for (int p : pos) {
                            ans[p] = x;
                        }

                        // Remove these 4 positions
                        vector<int> newEmpty;

                        for (int p : empty) {

                            if (p != pos[0] &&
                                p != pos[1] &&
                                p != pos[2] &&
                                p != pos[3]) {

                                newEmpty.push_back(p);
                            }
                        }

                        empty = newEmpty;

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    possible = false;
                    break;
                }
            }

            if (possible) {

                for (int x : ans) {
                    cout << x << " ";
                }

                cout << "\n";
                break;
            }
        }
    }

    return 0;
}