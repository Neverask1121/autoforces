#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        vector<int> A(7);
        int sum = 0;

        for (int i = 0; i < 7; i++) {
            cin >> A[i];
            sum += A[i];
        }

        int mx = *max_element(A.begin(), A.end());

        int ans = 2 * mx - sum;

        cout << ans << endl;
    }

    return 0;
}