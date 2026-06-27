#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        vector<vector<int>> bucket(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            bucket[a[i]].push_back(i);
        }

        vector<long long> cnt(n + 1, 0);

        long long base = 0;
        long long k = 0;
        long long sumPos = 0;

        // Process every height level from top to bottom
        for (int h = n; h >= 1; h--) {
            for (int idx : bucket[h]) {
                k++;
                sumPos += idx;
            }

            cnt[h] = k;

            // k cubes at this height will move to rightmost k positions
            long long finalPosSum = k * (2LL * n - k + 1) / 2;
            base += finalPosSum - sumPos;
        }

        long long bestGain = 0;

        for (int i = 1; i <= n; i++) {
            long long h = a[i];

            /*
                If we remove the top cube from column i,
                only row h changes.

                Gain = i + count(height >= h) - n - 1
            */
            long long gain = i + cnt[h] - n - 1;
            bestGain = max(bestGain, gain);
        }

        cout << base + bestGain << '\n';
    }

    return 0;
}