#include <bits/stdc++.h>
using namespace std;

int getLength(string &s, char start) {

    char need = start;
    int len = 0;

    for (char c : s) {

        if (c == need) {
            len++;

            if (need == '0')
                need = '1';
            else
                need = '0';
        }
    }

    return len;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        int count0 = 0;
        int count1 = 0;

        for (char c : s) {
            if (c == '0')
                count0++;
            else
                count1++;
        }

        int diff = count0 - count1;

        // Impossible
        if (abs(diff) > 2) {
            cout << -1 << '\n';
            continue;
        }

        int len0 = getLength(s, '0');
        int len1 = getLength(s, '1');

        int best = -1;

        // Remaining difference = 0
        if (abs(diff) <= 1) {

            int len = max(len0, len1);

            // Difference 0 => equal number of 0s and 1s
            // => even length
            if (len % 2 == 1)
                len--;

            best = max(best, len);
        }

        // Remaining difference = +1
        if (abs(diff - 1) <= 1) {

            int len = len0;

            // Starts with 0 and odd length
            if (len % 2 == 0)
                len--;

            best = max(best, len);
        }

        // Remaining difference = -1
        if (abs(diff + 1) <= 1) {

            int len = len1;

            // Starts with 1 and odd length
            if (len % 2 == 0)
                len--;

            best = max(best, len);
        }

        cout << n - best << '\n';
    }

    return 0;
}