#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        // Alice deletes the first 0
        int pos0 = s.find('0');
        s.erase(pos0, 1);

        // Bob deletes the first 1
        int pos1 = s.find('1');
        s.erase(pos1, 1);

        cout << s << '\n';
    }

    return 0;
}