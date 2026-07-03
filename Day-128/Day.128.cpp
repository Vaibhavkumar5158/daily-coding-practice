#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const int MAXN = 1000000;

long long fact[MAXN + 1], invFact[MAXN + 1];

long long powerMod(long long base, long long exp) {
    long long ans = 1;

    base %= MOD;

    while (exp > 0) {
        if (exp & 1) ans = ans * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }

    return ans;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[MAXN] = powerMod(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        long long waysChooseSet = nCr(n, m);

        long long sum = 0;

        for (int i = 0; i <= n - m; i++) {
            long long cur = nCr(n - m, i) * powerMod(n - i - 1, n - 1) % MOD;

            if (i % 2 == 0) {
                sum = (sum + cur) % MOD;
            } else {
                sum = (sum - cur + MOD) % MOD;
            }
        }

        long long ans = waysChooseSet;
        ans = ans * (n - 1) % MOD;
        ans = ans * sum % MOD;

        cout << ans << '\n';
    }

    return 0;
}