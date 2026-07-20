#include <bits/stdc++.h>
using namespace std;

vector<int> cap, levelCnt, cur;
vector<vector<int>> atLevel;
vector<int> ans;
int k;

bool makeSpace(int lv) {
    if (lv == k + 1) return true;
    if (levelCnt[lv] < cap[lv]) return true;

    if (!makeSpace(lv + 1)) return false;

    if (atLevel[lv].empty()) return false;

    int id = atLevel[lv].back();
    atLevel[lv].pop_back();

    cur[id]++;
    levelCnt[lv]--;
    if (cur[id] <= k) {
        atLevel[cur[id]].push_back(id);
        levelCnt[cur[id]]++;
    }
    ans.push_back(id);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n >> k;

        cap.assign(k + 2, n);
        for (int i = 1; i <= k; i++) cin >> cap[i];

        cur.assign(n + 1, 0);
        levelCnt.assign(k + 2, 0);
        atLevel.assign(k + 2, {});
        ans.clear();

        for (int i = 1; i <= n; i++) {
            cin >> cur[i];
            if (cur[i] <= k) {
                levelCnt[cur[i]]++;
                atLevel[cur[i]].push_back(i);
            }
        }

        bool ok = true;

        for (int i = 1; i <= n && ok; i++) {
            while (cur[i] <= k) {
                if (!makeSpace(cur[i] + 1)) {
                    ok = false;
                    break;
                }

                auto &v = atLevel[cur[i]];
                auto it = find(v.begin(), v.end(), i);
                if (it != v.end()) v.erase(it);

                levelCnt[cur[i]]--;
                cur[i]++;

                if (cur[i] <= k) {
                    atLevel[cur[i]].push_back(i);
                    levelCnt[cur[i]]++;
                }

                ans.push_back(i);
            }
        }

        if (!ok || ans.size() > 1000) {
            cout << -1 << '\n';
        } else {
            cout << ans.size() << '\n';
            for (int x : ans) cout << x << " ";
            cout << '\n';
        }
    }

    return 0;
}