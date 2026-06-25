#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n + 1), b(n + 1);

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<vector<int>> canStart(n + 1);
        bool impossible = false;

        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();

            if (pos > n) {
                impossible = true;
                break;
            }

            canStart[pos].push_back(i);
        }

        if (impossible) {
            cout << -1 << '\n';
            continue;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        Fenwick fw(n);

        long long ans = 0;
        bool ok = true;

        for (int target = 1; target <= n; target++) {
            for (int idx : canStart[target]) {
                pq.push(idx);
            }

            if (pq.empty()) {
                ok = false;
                break;
            }

            int idx = pq.top();
            pq.pop();

            int alreadyChosen = target - 1;
            int chosenBeforeIdx = fw.sum(idx);

            ans += alreadyChosen - chosenBeforeIdx;

            fw.add(idx, 1);
        }

        if (!ok) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n + 1), b(n + 1);

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<vector<int>> canStart(n + 1);
        bool impossible = false;

        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();

            if (pos > n) {
                impossible = true;
                break;
            }

            canStart[pos].push_back(i);
        }

        if (impossible) {
            cout << -1 << '\n';
            continue;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        Fenwick fw(n);

        long long ans = 0;
        bool ok = true;

        for (int target = 1; target <= n; target++) {
            for (int idx : canStart[target]) {
                pq.push(idx);
            }

            if (pq.empty()) {
                ok = false;
                break;
            }

            int idx = pq.top();
            pq.pop();

            int alreadyChosen = target - 1;
            int chosenBeforeIdx = fw.sum(idx);

            ans += alreadyChosen - chosenBeforeIdx;

            fw.add(idx, 1);
        }

        if (!ok) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}