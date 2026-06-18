#include <bits/stdc++.h>
using namespace std;

class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(int size) {
        n = size;
        tree.assign(4 * n, -1);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int findMex(int node, int start, int end, int l) {
        if (tree[node] >= l) return -1;

        if (start == end) return start;

        int mid = (start + end) / 2;

        int leftAns = findMex(2 * node, start, mid, l);
        if (leftAns != -1) return leftAns;

        return findMex(2 * node + 1, mid + 1, end, l);
    }
};

void manacher(vector<int>& a, vector<int>& d1, vector<int>& d2) {
    int n = a.size();

    d1.assign(n, 0);
    d2.assign(n, 0);

    int l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

        while (i - k >= 0 && i + k < n && a[i - k] == a[i + k]) {
            k++;
        }

        d1[i] = k;

        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

        while (i - k - 1 >= 0 && i + k < n && a[i - k - 1] == a[i + k]) {
            k++;
        }

        d2[i] = k;

        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }
}

bool isPalindrome(int l, int r, vector<int>& d1, vector<int>& d2) {
    int len = r - l + 1;

    if (len % 2 == 1) {
        int mid = (l + r) / 2;
        return d1[mid] >= len / 2 + 1;
    } else {
        int mid = (l + r + 1) / 2;
        return d2[mid] >= len / 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int m = 2 * n;
        vector<int> a(m);

        vector<vector<int>> pos(n);

        for (int i = 0; i < m; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        vector<int> d1, d2;
        manacher(a, d1, d2);

        vector<pair<int, int>> queries;

        for (int x = 0; x < n; x++) {
            int l = pos[x][0];
            int r = pos[x][1];

            if (isPalindrome(l, r, d1, d2)) {
                queries.push_back({l, r});
            }
        }

        sort(queries.begin(), queries.end(), [](auto &p1, auto &p2) {
            return p1.second < p2.second;
        });

        SegTree seg(n + 1);

        int ans = 1; 
        int ptr = 0;

        for (auto [l, r] : queries) {
            while (ptr <= r) {
                seg.update(1, 0, n, a[ptr], ptr);
                ptr++;
            }

            int mex = seg.findMex(1, 0, n, l);
            ans = max(ans, mex);
        }

        cout << ans << '\n';
    }

    return 0;
}