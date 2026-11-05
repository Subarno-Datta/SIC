# include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int prev = 0, len = 0, maxLen = 0;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;

        if (temp >= prev) {
            len++;
            maxLen = max(len, maxLen);
        } else len = 1;
        prev = temp;
    }

    cout << maxLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
