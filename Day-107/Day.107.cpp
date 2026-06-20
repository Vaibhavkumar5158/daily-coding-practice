#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

struct Ratio {
    long long num, den; 
};

// returns true if r < a / b
bool lessThanTarget(const Ratio& r, long long a, long long b) {
    return (__int128)r.num * b < (__int128)r.den * a;
}

// sort ratio by num / den
bool cmpRatio(const Ratio& x, const Ratio& y) {
    return (__int128)x.num * y.den < (__int128)y.num * x.den;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        vector<Ratio> ratios;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                // ratio = b[j] / b[i]
                ratios.push_back({b[j], b[i]});
            }
        }

        sort(ratios.begin(), ratios.end(), cmpRatio);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // Need: a[i] * b[x] > a[j] * b[y]
                // Same as: b[y] / b[x] < a[i] / a[j]

                int l = 0, r = ratios.size();

                while (l < r) {
                    int mid = (l + r) / 2;

                    if (lessThanTarget(ratios[mid], a[i], a[j])) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }

                total = (total + l) % MOD;
            }
        }

        long long denom = 1LL * n * (n - 1) % MOD;
        long long invDenom = modPow(denom, MOD - 2);

        cout << total * invDenom % MOD << '\n';
    }

    return 0;
}