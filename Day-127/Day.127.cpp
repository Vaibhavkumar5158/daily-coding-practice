#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long powerMod(long long base, long long exp) {
    long long ans = 1;

    while (exp > 0) {
        if (exp & 1) {
            ans = (ans * base) % MOD;
        }

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        long long totalCells = n * m;

        long long rowPositions = n - r + 1;
        long long colPositions = m - c + 1;

        long long equations = rowPositions * colPositions;

        long long freeCells = totalCells - equations;

        cout << powerMod(2, freeCells) << '\n';
    }

    return 0;
}