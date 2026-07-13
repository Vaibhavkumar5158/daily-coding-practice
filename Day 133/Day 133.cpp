#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

const int MAXN = 200000;

int mu[MAXN + 1];
int prime[MAXN + 1], pcnt;
bool vis[MAXN + 1];
int divs[MAXN + 1];
int64 F[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mu[1] = 1;
    for (int i = 2; i <= MAXN; i++) mu[i] = 0;

    for (int i = 2; i <= MAXN; i++) {
        if (!vis[i]) {
            prime[pcnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < pcnt && 1LL * i * prime[j] <= MAXN; j++) {
            int x = i * prime[j];
            vis[x] = true;
            if (i % prime[j] == 0) {
                mu[x] = 0;
                break;
            } else {
                mu[x] = -mu[i];
            }
        }
    }

    mu[1] = 1;

    for (int i = 1; i <= MAXN; i++)
        for (int j = i; j <= MAXN; j += i)
            divs[j]++;

    for (int d = 1; d <= MAXN; d++) {
        if (mu[d] == 0) continue;
        for (int m = d; m <= MAXN; m += d) {
            int t = m / d;
            F[m] += 1LL * mu[d] * t * t;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int64 ans = 0;

        for (int g = 1; g <= n; g++)
            ans += 1LL * divs[g] * F[n / g];

        cout << ans << '\n';
    }
}