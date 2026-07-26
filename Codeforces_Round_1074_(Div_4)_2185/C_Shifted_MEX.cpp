#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Step 1: sort
        sort(a.begin(), a.end());

        // Step 2: remove duplicates
        a.erase(unique(a.begin(), a.end()), a.end());

        int best = 0;
        int curr = 1;

        // Step 3: longest consecutive sequence
        for (int i = 1; i < (int)a.size(); i++) {
            if (a[i] == a[i - 1] + 1) {
                curr++;
            } else {
                best = max(best, curr);
                curr = 1;
            }
        }

        best = max(best, curr);

        // Step 4: answer
        cout << best << "\n";
    }

    return 0;
}
